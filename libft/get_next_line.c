/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:10:39 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 10:27:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkerrors(int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || read(fd, buf, 0) == -1)
		return (-1);
	return (0);
}

int		lastline(char **line, char **str, int i)
{
	if (i == 0)
	{
		*line = "";
		return (0);
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		(*str) = (*str) + i;
		return (1);
	}
}

char	*readfile(char *str, int fd)
{
	int		size;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	size = 1;
	while (!(ft_strchr(str, '\n')) && size > 0)
	{
		size = read(fd, buff, BUFF_SIZE);
		if (size > 0)
		{
			buff[size] = '\0';
			tmp = str;
			if (!(str = ft_strjoin(tmp, buff)))
				return (NULL);
			free(tmp);
		}
	}
	return (str);
}

int		stock(char **str, char **line)
{
	int		i;
	char	*save;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		if (!(save = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1)))
			return (-1);
		(*str)[i] = '\0';
		*line = ft_strdup(*str);
		free(*str);
		*str = save;
		return (1);
	}
	if ((*str)[i] == '\0')
	{
		if (lastline(line, str, i) == 1)
			return (1);
		return (0);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				i;

	i = 0;
	if (checkerrors(fd, line) == -1)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	if ((str = readfile(str, fd)) == NULL)
		return (-1);
	return (stock(&str, line));
}

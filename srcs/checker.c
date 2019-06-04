/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/04 19:34:54 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkline(char *line, char *str)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
		return (0);
	if (line[0] == 's' && line[1] == 'a')
		

}

int		main(int ac, char **av)
{
	int		ret;
	int		check;
	char	*line;

	ret = 1;
	check = 1;
	while (ret == 1 && check != 0)
	{
		ret = get_next_line(0, &line);
		if (line[0] != '\0')
			check = checkline(line, *av[1]);
	}
	ft_putstr("OK\n");
	return (0);
}

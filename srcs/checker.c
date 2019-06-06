/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/06 19:16:54 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		set_stack(t_stack *s, char **av)
{
	size_t	i;
	size_t	j;

	i = ft_tabsize(av);
	j = 0;
	if (!(s->a = (char **)malloc(sizeof(char *) * (sizeof(i + 1)))))
		return (-1);
	while (j < i)
	{
		s->a[j] = av[j + 1];
		++j;
	}
	s->a[j] = NULL;
	if (!(s->b = (char **)malloc(sizeof(char *) * ft_tabsize(s->a) + 1)))
		return (0);
	i = 0;
	while (i < j)
		s->b[i++] = NULL;
	ft_displaytab(s->a);
	return (1);
}

void	swap_b(t_stack *s)
{
	char	*tmp;

	tmp = s->b[0];
	s->b[0] = s->b[1];
	s->b[1] = tmp;
}

void	swap_a(t_stack *s)
{
	char	*tmp;

	tmp = s->a[0];
	s->a[0] = s->a[1];
	s->a[1] = tmp;
}

int		checkline(char *line, t_stack *s)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
		return (0);
	else if (line[0] == 's' && line[1] == 'a' && (!(line[2])))
		swap_a(s);
	else if (line[0] == 's' && line[1] == 'b' && (!(line[2])) && s->b[0])
		swap_b(s);
	else if (line[0] == 's' && line[1] == 's' && (!(line[2])))
	{
		swap_a(s);
		swap_b(s);
	}
	else if (line[0] == 'p' && line[1] == 'a' && (!(line[2])) && s->b[0])
		push_a(s);
	else if (line[0] == 'p' && line[1] == 'b' && (!(line[2])) && s->a[0])
		push_b(s);
	ft_displaytab(s->a);
	return (1);
}

int		main(int ac, char **av)
{
	int		ret;
	int		check;
	char	*line;
	t_stack	*s;

	(void)ac;
	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack(s, av)) == -1)
	{
		ft_putstr("KO\n");
		return (0);
	}
	ret = 1;
	check = 1;
	while (ret == 1 && check != 0)
	{
		ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			check = checkline(line, s);
			free(line);
		}
	}
	ft_putstr("OK\n");
	return (0);
}

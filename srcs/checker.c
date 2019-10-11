/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/11 19:23:56 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack(t_stack *s, char **av)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_tabsize(av) - 1;
	j = 0;
	k = 1;
	if (!(s->a = (int *)malloc(sizeof(int) * i)))
		return (-1);
	s->tabsize_a = i;
	s->tabsize_b = 0;
	s->write = 0;
	s->ret = 1;
	s->check = 1;
	if (!(s->b = (int *)malloc(sizeof(int) * i)))
		return (-1);
	while (j < i)
	{
		if (ft_atoi(av[k]) == -2147483645)
			return (-1);
		s->a[j] = ft_atoi(av[k]);
		++j;
		++k;
	}
	return (1);
}

void	swap_b(t_stack *s)
{
	int		tmp;

	if (s->tabsize_b > 1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	if (s->write == 1)
		ft_putstr("sb\n");
}

void	swap_a(t_stack *s)
{
	int		tmp;

	if (s->tabsize_a > 1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
	if (s->write == 1 && s->both == 0)
		ft_putstr("sa\n");
}

int		checkline(char *line, t_stack *s)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
	{
		free_stack(s);
		return (-1);
	}
	else if (!(ft_strcmp(line, "sa")))
		swap_a(s);
	else if (!(ft_strcmp(line, "sb")) && s->tabsize_b > 0)
		swap_b(s);
	else if (!(ft_strcmp(line, "ss")))
		swap_both(s);
	else if (!(ft_strcmp(line, "pa")) && s->tabsize_b > 0)
		push_a(s);
	else if (!(ft_strcmp(line, "pb")) && s->tabsize_a > 0)
		push_b(s);
	else if ((checkline2(line, s)) == -1)
	{
		free_stack(s);
		return (-1);
	}
	return (1);
}

int		checker(char **av)
{
	char	*line;
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack(s, av)) == -1)
		return (-1);
	if ((checkdupe(s)) == -1)
		return (-1);
	while (s->ret == 1 && s->check != 0)
	{
		s->ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			if ((checkline(line, s)) == -1)
				return (-1);
			free(line);
		}
	}
	if ((checktab(s)) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(s);
	return (0);
}

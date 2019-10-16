/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 14:46:40 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack_p(t_stack *s, int ac, char **av)
{
	if (!(s->a = (int *)malloc(sizeof(int) * (ac - 1))))
		return (-1);
	s->write = 0;
	s->ret = 1;
	s->check = 1;
	if (!(s->b = (int *)malloc(sizeof(int) * (ac - 1))))
		return (-1);
	if ((fill_stack_p(s, ac, av)) == -1)
	{
		free_stack_p(s);
		return (-1);
	}
	s->tabsize_a = ac - 1 - s->visual;
	s->tabsize_b = 0;
	return (1);
}

void	swap_b_p(t_stack *s)
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
	if (s->visual == 1)
		display_stacks(s);
}

void	swap_a_p(t_stack *s)
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
	if (s->visual == 1)
		display_stacks(s);
}

int		checkline_p(char *line, t_stack *s)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
	{
		free_stack_p(s);
		return (-1);
	}
	else if (!(ft_strcmp(line, "sa")))
		swap_a_p(s);
	else if (!(ft_strcmp(line, "sb")) && s->tabsize_b > 0)
		swap_b_p(s);
	else if (!(ft_strcmp(line, "ss")))
		swap_both_p(s);
	else if (!(ft_strcmp(line, "pa")))
		push_a_p(s);
	else if (!(ft_strcmp(line, "pb")))
		push_b_p(s);
	else if ((checkline2_p(line, s)) == -1)
	{
		free_stack_p(s);
		return (-1);
	}
	return (1);
}

int		checker_p(int ac, char **av)
{
	char	*line;
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack_p(s, ac, av)) == -1)
		return (-1);
	if ((checkdupe_p(s)) == -1)
		return (-1);
	while (s->ret == 1 && s->check != 0)
	{
		s->ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			if ((checkline_p(line, s)) == -1)
				return (-1);
			free(line);
		}
	}
	if ((checktab_p(s)) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack_p(s);
	return (0);
}

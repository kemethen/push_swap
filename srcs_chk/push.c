/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:09:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 14:46:34 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		fill_stack(t_stack *s, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		if (!(ft_strcmp(av[j], "-v")))
			s->visual = 1;
		else if (ft_atoi(av[j]) == -2147483645)
			return (-1);
		else
			s->a[i - s->visual] = ft_atoi(av[j]);
		++i;
		++j;
	}
	return (1);
}

void	fill_a(t_stack *s)
{
	int		tmp;
	size_t	i;

	tmp = s->b[0];
	i = s->tabsize_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[i] = tmp;
}

void	fill_b(t_stack *s)
{
	int		tmp;
	size_t	i;

	tmp = s->a[0];
	i = s->tabsize_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		--i;
	}
	s->b[i] = tmp;
}

void	push_a(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->tabsize_b > 0)
	{
		if (s->tabsize_a == 0)
			s->a[0] = s->b[0];
		else
			fill_a(s);
		while (i < s->tabsize_b)
		{
			s->b[i] = s->b[i + 1];
			++i;
		}
		s->tabsize_a++;
		s->tabsize_b--;
		if (s->write == 1)
			ft_putstr("pa\n");
		if (s->visual == 1)
			display_stacks(s);
	}
}

void	push_b(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->tabsize_a > 0)
	{
		if (s->tabsize_b == 0)
			s->b[0] = s->a[0];
		else
			fill_b(s);
		while (i < s->tabsize_a)
		{
			s->a[i] = s->a[i + 1];
			++i;
		}
		s->tabsize_a--;
		s->tabsize_b++;
		if (s->write == 1)
			ft_putstr("pb\n");
		if (s->visual == 1)
			display_stacks(s);
	}
}

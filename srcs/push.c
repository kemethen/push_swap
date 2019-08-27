/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:09:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/08/27 18:39:34 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (s->tabsize_a == 0)
		s->a[0] = s->b[0];
	else
		fill_a(s);
	i = 0;
	while (i < s->tabsize_b)
	{
		s->b[i] = s->b[i + 1];
		++i;
	}
	s->tabsize_a++;
	s->tabsize_b--;
	if (s->write == 1)
		ft_putstr("pa\n");
}

void	push_b(t_stack *s)
{
	size_t	i;

	if (s->tabsize_b == 0)
		s->b[0] = s->a[0];
	else
		fill_b(s);
	i = 0;
	while (i < s->tabsize_a)
	{
		s->a[i] = s->a[i + 1];
		++i;
	}
	s->tabsize_a--;
	s->tabsize_b++;
	if (s->write == 1)
		ft_putstr("pb\n");
}

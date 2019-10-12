/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:47:33 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/12 15:24:33 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(int *tab, int size)
{
	int		x;
	int		i;

	x = tab[0];
	i = 0;
	while (i < size)
	{
		if (x > tab[i])
			x = tab[i];
		++i;
	}
	return (x);
}

void	push_swap_four(t_stack *s)
{
	int		i;

	i = find_min(s->a, s->tabsize_a);
	while (s->a[0] != i)
	{
		if (s->a[3] == i)
			reverse_rotate_a(s);
		else
			rotate_a(s);
	}
	push_b(s);
	push_swap_three(s);
	push_a(s);
}

void	to_bottom_max(t_stack *s, int max)
{
	while (max != s->b[0])
		reverse_rotate_b(s);
	push_a(s);
}

void	to_top_max(t_stack *s, int max)
{
	while (max != s->b[0])
		rotate_b(s);
	push_a(s);
}

int		find_med_index(int *tab, int med)
{
	int		i;

	i = 0;
	while (tab[i] != med)
		++i;
	return (i);
}

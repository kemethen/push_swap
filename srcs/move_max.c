/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:09:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/08 16:16:53 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		number_min(int *tab, int size)
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

int		last_three(t_stack *s)
{
	int		x;
	int		y;
	int		z;
	size_t	i;

	x = find_max(s->a, s->tabsize_a);
	y = 0;
	z = 0;
	i = 0;
	while (i < s->tabsize_a)
	{
		if (y < s->a[i] && s->a[i] < x)
			y = s->a[i];
		++i;
	}
	i = 0;
	while (i < s->tabsize_a)
	{
		if (z < s->a[i] && s->a[i] < y)
			z = s->a[i];
		++i;
	}
	return (z);
}

int		bot_push(int *tab, int size, int med)
{
	int		i;

	i = size - 1;
	while (tab[i] >= med)
		--i;
	return (size - i);
}

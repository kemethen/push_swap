/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:09:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/08/21 16:54:16 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	to_bottom_max(t_stack *s, int max)
{
	//display_stacks(s);
	while (max != s->b[0])
	{		
		reverse_rotate_b(s);
	//	display_stacks(s);
	}
	push_a(s);
}

void	to_top_max(t_stack *s, int max)
{
	//display_stacks(s);
	while (max != s->b[0])
	{		
		rotate_b(s);
	//	display_stacks(s);
	}
	push_a(s);
}

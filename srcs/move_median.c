/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:24:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/09 18:34:10 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_stack *s)
{
	ft_putstr("----------------------STACK A----------------------\n");
	ft_displaytabint(s->a, s->tabsize_a);
	ft_putstr("----------------------STACK A----------------------\n");
	ft_putstr("----------------------STACK B----------------------\n");
	ft_displaytabint(s->b, s->tabsize_b);
	ft_putstr("----------------------STACK B----------------------\n");
}

void	to_bottom(t_stack *s, size_t i)
{
//	display_stacks(s);
	while (i < s->tabsize_a - 1)
	{		
		reverse_rotate_a(s);
		++i;
	//	display_stacks(s);
		if (s->a[0] < s->a[i])
		{
			push_b(s);
			--i;
	//		display_stacks(s);
		}
	}
}

void	to_top(t_stack *s, int i)
{
	display_stacks(s);
	while (i > 0)
	{
		rotate_a(s);
		i--;
	//	display_stacks(s);
		if (s->a[0] < s->a[i])
		{
			push_b(s);
			i--;
	//		display_stacks(s);
		}
	}
	rotate_a(s);
}

void	quicksort(t_stack *s)
{
	int		med_a;
	int		med_b;
	int		i;

	i  = 0;
	med_a = median(s->a, s->tabsize_a);
	med_b = median(s->b, s->tabsize_b);
//	ft_printf("med_a = %d\nmed_b = %d\n", med_a, med_b);
	//display_stacks(s);
	if ((size_t)med_a > s->tabsize_a / 2 - 1)
		to_bottom(s, med_a);
	else
		to_top(s, med_a);
	while (s->a[0] != med_a)
	{
		if (s->a[0] > med_a)
			rotate_a(s);
		else
		{
			++i;
			push_b(s);
		}
	//	display_stacks(s);
	}
	while (i != 0)
	{
		push_a(s);
		--i;
	}
	display_stacks(s);
	med_a = median(s->a, s->tabsize_a) - 1;
	if ((size_t)med_a > s->tabsize_a / 2 - 1)
		to_bottom(s, med_a);
	else
		to_top(s, med_a);
	ft_printf("med_a = %d\nmed_b = %d\n", med_a, med_b);
	display_stacks(s);
	while (s->a[0] != med_a)
	{
		if (s->a[0] > med_a)
			rotate_a(s);
		else
		{
			++i;
			push_b(s);
		}
	//	display_stacks(s);
	}
	while (i != 0)
	{
		push_a(s);
		--i;
	}
	display_stacks(s);
}

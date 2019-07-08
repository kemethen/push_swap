/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:24:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/08 17:56:51 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	to_bottom(t_stack *s, int i)
{
	ft_printf("i = %d\n", i);
	while (i < s->tabsize_a - 1)
	{
		reverse_rotate_a(s);
		i++;
	}
}

void	to_top(t_stack *s, int i)
{
	ft_printf("i = %d\n", i);
	while (i > 0)
	{
		rotate_a(s);
		i--;
	}
	rotate_a(s);
}

//void	quicksort(t_stack *s)
//{
//	int		med_a;
//	int		med_b;
//
//	med_a = median(s->a, s->tabsize_a);
//	med_b = median(s->b, s->tabsize_b);
//}

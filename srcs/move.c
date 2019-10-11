/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:47:33 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/11 19:23:59 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

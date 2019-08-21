/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:55:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/08/21 19:17:58 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		median(int *t1, int size)
{
	int		*t2;
	int		i;
	int		tmp;

	i = 1;
	t2 = ft_tabdupint(t1, size);
	while (i < size)
	{
		if (t2[i - 1] > t2[i])
		{
			tmp = t2[i - 1];
			t2[i - 1] = t2[i];
			t2[i] = tmp;
			i = 0;
		}
		i++;
	}
	i = size / 2;
	tmp = t2[i];
	free(t2);
	return (tmp);
}

int		mean_value(int *t1, int size)
{
	int		i;
	int		mv;

	i = 0;
	mv = 0;
	while (i < size)
	{
		mv += t1[i];
		i++;
	}
	mv /= size;
	return (mv);
}

void	sort_b(t_stack *s)
{
	int		mv;

	mv = mean_value(s->b, s->tabsize_b);
	if (s->b[0] > mv)
		rotate_b(s);
}

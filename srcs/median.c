/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:55:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/02 17:08:46 by kemethen         ###   ########.fr       */
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

void	sort_b(t_stack *s, int top, int bot, int med)
{
	int		mv;

	mv = mean_value(s->b, s->tabsize_b);
	top = top_push(s->a, med);
	bot = bot_push(s->a, s->tabsize_a, med);
	if (s->b[0] < mv)
	{
		if (top < bot)
			rotate_both(s);
		else
			rotate_b(s);
	}
}

void	split_stack(t_stack *s)
{
	int		med;
	int		top;
	int		bot;
	int		max;
	size_t	i = s->tabsize_a / 2;

	max = last_three(s);
	med = median(s->a, s->tabsize_a);
	while (i < s->tabsize_a)
	{
		if (s->a[0] < med && s->a[0] < max)
			{
				push_b(s);
				sort_b(s, top, bot, med);
	//			ft_putstr("APRES LE SORT\n");
	//			display_stacks(s);
			}
			top = top_push(s->a, med);
			bot = bot_push(s->a, s->tabsize_a, med);
			while (s->a[0] >= med && i < s->tabsize_a)
			{
				if (top > bot)
					reverse_rotate_a(s);
				else
					rotate_a(s);
			}			
//			display_stacks(s);
	}
	while (s->tabsize_a > 3)
	{
		med = median(s->a, s->tabsize_a);
//		ft_printf("med = %d\nmax = %d\n", med, max);
		if (s->a[0] < med && s->a[0] < max)
		{
			push_b(s);
			sort_b(s, top, bot, med);
//			ft_putstr("APRES LE SORT\n");
//			display_stacks(s);
		}
		top = top_push(s->a, med);
		bot = bot_push(s->a, s->tabsize_a, med);
		while (s->a[0] >= med)
		{
			if (top > bot)
				reverse_rotate_a(s);
			else
				rotate_a(s);
		}
//		ft_putstr("APRES LE ROTATE\n");
	//	display_stacks(s);
	}
	push_swap_three(s);
//	display_stacks(s);
	sort(s);
//	display_stacks(s);
}
    
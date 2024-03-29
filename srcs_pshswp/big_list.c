/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:41:09 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 14:46:39 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_p(int *tab, int size)
{
	int		x;
	int		i;

	x = tab[0];
	i = 0;
	while (i < size)
	{
		if (x < tab[i])
			x = tab[i];
		++i;
	}
	return (x);
}

void	check_next(t_stack *s)
{
	if (s->top > s->bot)
		reverse_rotate_a_p(s);
	else
		rotate_a_p(s);
}

int		dupstack(t_stack *s, int size)
{
	size_t	i;
	int		tmp;
	int		*tab;

	i = 1;
	tmp = 0;
	tab = ft_tabdupint(s->a, s->tabsize_a);
	while (i < s->tabsize_a)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		i++;
	}
	tmp = tab[size - 1];
	free(tab);
	return (tmp);
}

void	big_list2(t_stack *s, int med)
{
	s->max = last_three_p(s);
	while (s->tabsize_a > 3)
	{
		med = median(s->a, s->tabsize_a);
		if (s->a[0] < med && s->a[0] < s->max)
		{
			push_b_p(s);
			sort_b(s, s->top, s->bot, med);
		}
		s->top = top_push(s->a, med);
		s->bot = bot_push_p(s->a, s->tabsize_a, med);
		while (s->a[0] >= med)
		{
			if (s->top > s->bot)
				reverse_rotate_a_p(s);
			else
				rotate_a_p(s);
		}
	}
	push_swap_three(s);
	sort(s);
}

void	big_list(t_stack *s)
{
	int		med;
	int		tmp;
	int		tmp2;

	tmp = s->tabsize_a / 10;
	while (s->cnt < 9)
	{
		tmp2 = tmp;
		med = dupstack(s, tmp);
		while (tmp2 > 0)
		{
			if (s->a[0] <= med)
			{
				push_b_p(s);
				tmp2--;
			}
			s->top = top_push(s->a, med);
			s->bot = bot_push_p(s->a, s->tabsize_a, med);
			while (s->a[0] > med && tmp2 > 0)
				check_next(s);
		}
		s->cnt++;
	}
	big_list2(s, med);
}

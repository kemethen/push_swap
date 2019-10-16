/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:55:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/15 13:00:30 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack_arg(t_stack *s, int ac, char **av)
{
	char	**tab;
	size_t	i;

	tab = ft_strsplit(av[1], ' ');
	s->tabsize_a = ft_tabsize(tab);
	i = -1;
	if ((ac == 3 && (!(ft_strcmp(av[2], "-v")))))
		s->visual = 1;
	if (!(s->a = (int *)malloc(sizeof(int) * s->tabsize_a)))
		return (-1);
	if (!(s->b = (int *)malloc(sizeof(int) * s->tabsize_a)))
		return (-1);
	s->tabsize_b = 0;
	while (++i < s->tabsize_a)
	{
		if (((ft_atoi(tab[i])) == -2147483645))
		{
			ft_freetab(tab);
			free_stack_p(s);
			return (-1);
		}
		s->a[i] = ft_atoi(tab[i]);
	}
	ft_freetab(tab);
	return (1);
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
	bot = bot_push_p(s->a, s->tabsize_a, med);
	if (s->b[0] < mv)
	{
		if (top < bot && s->a[0] > med)
			rotate_both_p(s);
		else
			rotate_b_p(s);
	}
}

void	split_stack(t_stack *s)
{
	int		med;
	int		top;
	int		bot;

	s->max = last_three_p(s);
	while (s->tabsize_a > 3)
	{
		med = median(s->a, s->tabsize_a);
		if (s->a[0] < med && s->a[0] < s->max)
		{
			push_b_p(s);
			sort_b(s, top, bot, med);
		}
		top = top_push(s->a, med);
		bot = bot_push_p(s->a, s->tabsize_a, med);
		while (s->a[0] >= med)
		{
			if (top > bot)
				reverse_rotate_a_p(s);
			else
				rotate_a_p(s);
		}
	}
	push_swap_three(s);
	sort(s);
}

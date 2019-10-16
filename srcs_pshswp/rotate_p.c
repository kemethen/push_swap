/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:18:29 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/16 17:18:48 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_p(t_stack *s)
{
	int		tmp;
	size_t	i;

	i = s->tabsize_a - 1;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[0] = tmp;
	if (s->write == 1)
		ft_putstr("rra\n");
	if (s->visual == 1 && s->both == 0)
		display_stacks(s);
}

void	reverse_rotate_b_p(t_stack *s)
{
	int		tmp;
	size_t	i;

	i = s->tabsize_b - 1;
	tmp = s->b[i];
	if (s->tabsize_b > 0)
	{
		while (i > 0)
		{
			s->b[i] = s->b[i - 1];
			--i;
		}
		s->b[0] = tmp;
		if (s->write == 1)
			ft_putstr("rrb\n");
	}
	if (s->visual == 1 && s->both == 0)
		display_stacks(s);
}

void	rotate_a_p(t_stack *s)
{
	int		tmp;
	size_t	i;

	tmp = s->a[0];
	i = 0;
	while (i < s->tabsize_a)
	{
		s->a[i] = s->a[i + 1];
		++i;
	}
	s->a[i - 1] = tmp;
	if (s->write == 1 && s->both == 0)
		ft_putstr("ra\n");
	if (s->visual == 1 && s->both == 0)
		display_stacks(s);
}

void	rotate_b_p(t_stack *s)
{
	int		tmp;
	size_t	i;

	tmp = s->b[0];
	i = 0;
	if (s->tabsize_b > 0)
	{
		while (i < s->tabsize_b)
		{
			s->b[i] = s->b[i + 1];
			i++;
		}
		s->b[i - 1] = tmp;
		if (s->write == 1 && s->both == 0)
			ft_putstr("rb\n");
	}
	if (s->visual == 1 && s->both == 0)
		display_stacks(s);
}

void	split_stack2(t_stack *s, int top, int bot, int med)
{
	s->max = last_three_p(s);
	while (s->tabsize_a > 3)
	{
		med = median(s->a, s->tabsize_a);
		if (s->a[0] < med && s->a[0] < s->max)
			push_b_p(s);
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

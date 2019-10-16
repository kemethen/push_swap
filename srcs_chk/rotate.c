/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:18:29 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 14:46:35 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_stack *s)
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

void	reverse_rotate_b(t_stack *s)
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

void	rotate_a(t_stack *s)
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

void	rotate_b(t_stack *s)
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

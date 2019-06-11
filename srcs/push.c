/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:09:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/11 17:47:12 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_stack *s)
{
	char	*tmp;
	size_t	i;

	tmp = s->b[0];
	i = ft_tabsize(s->a);
	s->a[i + 1] = NULL;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[i] = tmp;
}

void	fill_b(t_stack *s)
{
	char	*tmp;
	size_t	i;

	tmp = s->a[0];
	i = ft_tabsize(s->b);
	s->b[i + 1] = NULL;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		--i;
	}
	s->b[i] = tmp;
}

void	push_a(t_stack *s)
{
	size_t	i;

	if (s->a[0] == NULL)
		s->a[0] = s->b[0];
	else
		fill_a(s);
	i = 0;
	while (i < ft_tabsize(s->b))
	{
		s->b[i] = s->b[i + 1];
		++i;
	}
}

void	push_b(t_stack *s)
{
	size_t	i;

	if (s->b[0] == NULL)
		s->b[0] = s->a[0];
	else
		fill_b(s);
	i = 0;
	while (i < ft_tabsize(s->a))
	{
		s->a[i] = s->a[i + 1];
		++i;
	}
}

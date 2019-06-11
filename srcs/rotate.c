/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:18:29 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/11 17:47:09 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *s)
{
	char	*tmp;
	size_t	i;

	i = ft_tabsize(s->a) - 1;
	tmp = s->a[i];
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		--i;
	}
	s->a[0] = tmp;
}

void	reverse_rotate_b(t_stack *s)
{
	char	*tmp;
	size_t	i;

	i = ft_tabsize(s->b) - 1;
	tmp = s->b[i];
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		--i;
	}
	s->b[0] = tmp;
}

void	rotate_a(t_stack *s)
{
	char	*tmp;
	size_t	i;

	tmp = s->a[0];
	i = 0;
	while (s->a[i] != NULL)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i - 1] = tmp;
}

void	rotate_b(t_stack *s)
{
	char	*tmp;
	size_t	i;

	tmp = s->b[0];
	i = 0;
	while (s->b[i] != NULL)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i - 1] = tmp;
}

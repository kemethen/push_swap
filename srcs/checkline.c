/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:45:19 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/08 17:15:56 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkline2(char *line, t_stack *s)
{
	if (!(ft_strcmp(line, "rr")))
	{
		s->both = 1;
		if (s->tabsize_a > 0)
			rotate_a(s);
		if (s->tabsize_b > 0)
			rotate_b(s);
		if (s->write == 1)
			ft_putstr("rr\n");
		s->both = 0;
	}
	else if (!(ft_strcmp(line, "rra")) && s->tabsize_a > 0)
		reverse_rotate_a(s);
	else if (!(ft_strcmp(line, "rrb")) && s->tabsize_b > 0)
		reverse_rotate_b(s);
	else if (!(ft_strcmp(line, "rrr")))
	{
		s->both = 1;
		if (s->tabsize_a > 0)
			rotate_a(s);
		if (s->tabsize_b > 0)
			rotate_b(s);
		if (s->write == 1)
			ft_putstr("rrr\n");
		s->both = 0;
	}
}

int		checktab(t_stack *s)
{
	size_t	i;

	i = 1;
	if (s->tabsize_b == 0)
	{
		while (s->a[i - 1] < s->a[i] && i < s->tabsize_a)
			i++;
	}
	if (i == s->tabsize_a && s->tabsize_b == 0)
		return (1);
	return (0);
}

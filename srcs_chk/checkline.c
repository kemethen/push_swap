/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:45:19 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 14:46:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_both(t_stack *s)
{
	s->both = 1;
	if (s->tabsize_a > 0)
		reverse_rotate_a(s);
	if (s->tabsize_b > 0)
		reverse_rotate_b(s);
	if (s->write == 1)
		ft_putstr("rrr\n");
	if (s->visual == 1)
		display_stacks(s);
	s->both = 0;
}

void	rotate_both(t_stack *s)
{
	s->both = 1;
	if (s->tabsize_a > 0)
		rotate_a(s);
	if (s->tabsize_b > 0)
		rotate_b(s);
	if (s->write == 1)
		ft_putstr("rr\n");
	if (s->visual == 1)
		display_stacks(s);
	s->both = 0;
}

void	swap_both(t_stack *s)
{
	s->both = 1;
	swap_a(s);
	swap_b(s);
	if (s->write == 1)
		ft_putstr("ss\n");
	s->both = 0;
	if (s->visual == 1)
		display_stacks(s);
}

int		checkline2(char *line, t_stack *s)
{
	if (!(ft_strcmp(line, "ra")))
		rotate_a(s);
	else if (!(ft_strcmp(line, "rb")))
		rotate_b(s);
	else if (!(ft_strcmp(line, "rr")))
		rotate_both(s);
	else if (!(ft_strcmp(line, "rra")))
		reverse_rotate_a(s);
	else if (!(ft_strcmp(line, "rrb")))
		reverse_rotate_b(s);
	else if (!(ft_strcmp(line, "rrr")))
		reverse_rotate_both(s);
	else
		return (-1);
	return (1);
}

int		checktab(t_stack *s)
{
	size_t	i;

	i = 0;
	if (s->tabsize_b != 0)
		return (-1);
	while (i < s->tabsize_a - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

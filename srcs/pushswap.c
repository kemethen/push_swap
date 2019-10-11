/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:03:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/11 19:24:03 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
	{
		if (s->a[1] > s->a[2])
		{
			swap_a(s);
			reverse_rotate_a(s);
		}
		else
			rotate_a(s);
	}
	else if (s->a[0] > s->a[1] || s->a[0] > s->a[2])
	{
		if (s->a[1] < s->a[2])
			swap_a(s);
		else
			reverse_rotate_a(s);
	}
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		reverse_rotate_a(s);
		swap_a(s);
	}
}

void	push_swap_two(t_stack *s)
{
	if (s->a[0] > s->a[1])
		swap_a(s);
}

int		push_swap(char **av)
{
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack(s, av)) == -1)
		return (-1);
	s->push_swap = 1;
	if ((checktab(s)) == 1)
		return (0);
	s->write = 1;
	if ((checkdupe(s)) == -1)
		return (-1);
	if (s->tabsize_a == 2)
		push_swap_two(s);
	else if (s->tabsize_a == 3)
		push_swap_three(s);
	else if (s->tabsize_a > 3 && s->tabsize_a < 120)
		split_stack(s);
	else
		big_list(s);
	free_stack(s);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 1)
		return (-1);
	if ((push_swap(av)) == -1)
		ft_putstr("Error\n");
	return (0);
}

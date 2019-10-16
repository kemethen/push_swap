/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:03:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/15 12:31:01 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
	{
		if (s->a[1] > s->a[2])
		{
			swap_a_p(s);
			reverse_rotate_a_p(s);
		}
		else
			rotate_a_p(s);
	}
	else if (s->a[0] > s->a[1] || s->a[0] > s->a[2])
	{
		if (s->a[1] < s->a[2])
			swap_a_p(s);
		else
			reverse_rotate_a_p(s);
	}
	else if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		reverse_rotate_a_p(s);
		swap_a_p(s);
	}
}

void	push_swap_two(t_stack *s)
{
	if (s->a[0] > s->a[1])
		swap_a_p(s);
}

int		push_swap(int ac, char **av)
{
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack_p(s, ac, av)) == -1)
		return (-1);
	s->push_swap = 1;
	s->write = 1;
	if ((checkdupe_p(s)) == -1)
		return (-1);
	if ((checktab_p(s)) == 1)
		return (0);
	if (s->tabsize_a == 2)
		push_swap_two(s);
	else if (s->tabsize_a == 3)
		push_swap_three(s);
	else if (s->tabsize_a == 4)
		push_swap_four(s);
	else if (s->tabsize_a < 120)
		split_stack(s);
	else if (s->tabsize_a >= 120)
		big_list(s);
	free_stack_p(s);
	return (0);
}

int		push_swap_arg(int ac, char **av)
{
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack_arg(s, ac, av)) == -1)
		return (-1);
	s->push_swap = 1;
	s->write = 1;
	if ((checkdupe_p(s)) == -1)
		return (-1);
	if ((checktab_p(s)) == 1)
		return (0);
	if (s->tabsize_a == 2)
		push_swap_two(s);
	else if (s->tabsize_a == 3)
		push_swap_three(s);
	else if (s->tabsize_a == 4)
		push_swap_four(s);
	else if (s->tabsize_a < 120)
		split_stack(s);
	else if (s->tabsize_a >= 120)
		big_list(s);
	free_stack_p(s);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		return (-1);
	if (ac == 2 || (ac == 3 && (!(ft_strcmp(av[2], "-v")))))
	{
		if ((push_swap_arg(ac, av)) == -1)
			ft_putstr("Error\n");
		return (1);
	}
	else if ((push_swap(ac, av)) == -1)
		ft_putstr("Error\n");
	return (0);
}

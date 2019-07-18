/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:03:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/18 18:13:39 by kemethen         ###   ########.fr       */
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

void	split_stack(t_stack *s)
{
	int		max;
	int		med;
	size_t	i;

	i = s->tabsize_a / 2 - 3;
	max = last_three(s);
	med = median(s->a, s->tabsize_a);
	while (i < s->tabsize_a)
	{
		if (s->a[0] < max && s->a[0] < med)
		{
			push_b(s);
			++i;
		}
		else
			rotate_a(s);
	}
//	ft_putstr("PREMIERE PARTIE\n");
//	display_stacks(s);
	while (s->tabsize_a > 3)
	{
		med = median(s->b, s->tabsize_b);
		if (s->a[0] < max)
		{
			push_b(s);
			if (s->b[0] < med)
				rotate_b(s);
		}
		else
			rotate_a(s);
	}
	push_swap_three(s);
//	ft_putstr("AVANT LE SORT\n");
//	display_stacks(s);
	quicksort(s);
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
	{
		ft_putstr("KO\n");
		return (0);
	}
	s->write = 1;
	if (s->tabsize_a == 2)
		push_swap_two(s);
	else if (s->tabsize_a == 3)
		push_swap_three(s);
	else
		split_stack(s);
//	display_stacks(s);
	free(s->a);
	free(s->b);
	free(s);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	push_swap(av);
	return (0);
}

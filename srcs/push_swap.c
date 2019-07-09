/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:03:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/09 17:50:32 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_stack *s)
{
	int		med;
	size_t	i;

	i = 0;
	med = median(s->a, s->tabsize_a);
	while (s->a[i] != med)
		++i;
	if (i > s->tabsize_a / 2 - 1)
		to_bottom(s, i);
	else
		to_top(s, i);
	while (s->a[0] != med)
	{
	//	display_stacks(s);
		if (s->a[0] < med)
		{
			push_b(s);
			if (s->b[0] < s->b[1])
				rotate_b(s);
		}
		else
			rotate_a(s);
	}
	quicksort(s);
}

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

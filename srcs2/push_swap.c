/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:03:04 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/08 17:57:47 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

int		median(int *t1, int size)
{
	int		*t2;
	int		i;
	int		tmp;

	i = 1;
	t2 = ft_tabdupint(t1, size);
	while (i < size)
	{
		if (t2[i - 1] > t2[i])
		{
			tmp = t2[i - 1];
			t2[i - 1] = t2[i];
			t2[i] = tmp;
			i = 0;
		}
		i++;
	}
	ft_putstr("TAB DUP --------------------------------------------\n");
	ft_displaytabint(t2, size);
	i = size / 2;
	tmp = t2[i];
	ft_printf("TMP = %d\n", tmp);
	free(t2);
	return (tmp);
}

void	split_stack(t_stack *s)
{
	int		med;
	int		i;

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
		if (s->a[0] < med)
			push_b(s);
		else
			rotate_a(s);
	}
//	quicksort(s);
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
	ft_putstr("Stack A --------------------------------------------\n");
	ft_displaytabint(s->a, s->tabsize_a);
	ft_putstr("Stack B --------------------------------------------\n");
	ft_displaytabint(s->b, s->tabsize_b);
	return (0);
}

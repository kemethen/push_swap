/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:24:08 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/08 17:22:56 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max_index(int *tab, int size)
{
	int		x;
	int		i;
	int		j;

	x = tab[0];
	i = 0;
	j = 0;
	while (i < size)
	{
		if (x < tab[i])
		{
			x = tab[i];
			j = i;
		}
		++i;
	}
	return (j);
}

int		find_max(int *tab, int size)
{
	int		x;
	int		i;

	x = tab[0];
	i = 0;
	while (i < size)
	{
		if (x < tab[i])
			x = tab[i];
		++i;
	}
	return (x);
}

void	display_stacks(t_stack *s)
{
	ft_putstr("==========================STACK=A==========================\n");
	ft_displaytabint(s->a, s->tabsize_a);
	ft_putstr("==========================STACK=A==========================\n");
	ft_putstr("==========================STACK=B==========================\n");
	ft_displaytabint(s->b, s->tabsize_b);
	ft_putstr("==========================STACK=B==========================\n");
}

void	sort(t_stack *s)
{
	size_t	max;
	size_t	i;

	while (s->tabsize_b > 0)
	{
		max = find_max(s->b, s->tabsize_b);
		i = find_max_index(s->b, s->tabsize_b);
		if (i > s->tabsize_b / 2 - 1)
			to_bottom_max(s, max);
		else
			to_top_max(s, max);
	}
	display_stacks(s);
}

int		top_push(int *tab, int med)
{
	int		i;

	i = 0;
	while (tab[i] >= med)
		++i;
	return (i);
}

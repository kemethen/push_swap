/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:09:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/11 19:23:59 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checkdupe(t_stack *s)
{
	size_t	i;
	int		tmp;
	int		*tab;

	i = 1;
	tmp = 0;
	tab = ft_tabdupint(s->a, s->tabsize_a);
	while (i++ < s->tabsize_a)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
			i = 1;
		}
	}
	i = 0;
	while (i++ < s->tabsize_a)
	{
		if (tab[i] == tab[i + 1])
		{
			free(tab);
			return (-1);
		}
	}
	free(tab);
	return (1);
}

void	free_stack(t_stack *s)
{
	free(s->a);
	free(s->b);
	free(s);
}

int		last_three(t_stack *s)
{
	int		x;
	int		y;
	int		z;
	size_t	i;

	x = find_max(s->a, s->tabsize_a);
	y = 0;
	z = 0;
	i = 0;
	while (i < s->tabsize_a)
	{
		if (y < s->a[i] && s->a[i] < x)
			y = s->a[i];
		++i;
	}
	i = 0;
	while (i < s->tabsize_a)
	{
		if (z < s->a[i] && s->a[i] < y)
			z = s->a[i];
		++i;
	}
	return (z);
}

int		bot_push(int *tab, int size, int med)
{
	int		i;

	i = size - 1;
	while (tab[i] >= med)
		--i;
	return (size - i);
}

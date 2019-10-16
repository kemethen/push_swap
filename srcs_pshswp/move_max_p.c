/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:09:44 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/15 12:26:31 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_tab_p(t_stack *s, size_t i, int *tab)
{
	i = 0;
	while (i < s->tabsize_a - 1)
	{
		if (tab[i] == tab[i + 1])
		{
			free_stack_p(s);
			free(tab);
			return (-1);
		}
		++i;
	}
	return (1);
}

int		checkdupe_p(t_stack *s)
{
	size_t	i;
	int		tmp;
	int		*tab;

	i = 0;
	tmp = 0;
	tab = ft_tabdupint(s->a, s->tabsize_a);
	while (i < s->tabsize_a - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	if ((check_tab_p(s, i, tab)) == -1)
		return (-1);
	free(tab);
	return (1);
}

void	free_stack_p(t_stack *s)
{
	free(s->a);
	free(s->b);
	free(s);
}

int		last_three_p(t_stack *s)
{
	int		x;
	int		y;
	int		z;
	size_t	i;

	x = find_max_p(s->a, s->tabsize_a);
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

int		bot_push_p(int *tab, int size, int med)
{
	int		i;

	i = size - 1;
	while (tab[i] >= med)
		--i;
	return (size - i);
}

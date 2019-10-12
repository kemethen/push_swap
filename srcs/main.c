/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:31:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/12 15:46:12 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int ac, char **av)
{
	if (!(av[1]))
		return (0);
	if ((checker(ac, av)) == -1)
		ft_putstr("Error\n");
	return (0);
}

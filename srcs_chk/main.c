/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:31:28 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/16 17:30:25 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		set_stack_arg(t_stack *s, char **av)
{
	char	**tab;
	size_t	j;

	tab = ft_strsplit(av[1], ' ');
	s->tabsize_a = ft_tabsize(tab);
	j = -1;
	if (!(s->a = (int *)malloc(sizeof(int) * s->tabsize_a)))
		return (-1);
	s->ret = 1;
	s->check = 1;
	if (!(s->b = (int *)malloc(sizeof(int) * s->tabsize_a)))
		return (-1);
	s->tabsize_b = 0;
	while (++j < s->tabsize_a)
	{
		if ((ft_atoi(tab[j])) == -2147483645)
		{
			ft_freetab(tab);
			free_stack(s);
			return (-1);
		}
		s->a[j] = ft_atoi(tab[j]);
	}
	ft_freetab(tab);
	return (1);
}

int		checker_arg(char **av)
{
	char	*line;
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack_arg(s, av)) == -1)
		return (-1);
	if ((checkdupe(s)) == -1)
		return (-1);
	while (s->ret == 1 && s->check != 0)
	{
		s->ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			if ((checkline(line, s)) == -1)
				return (-1);
			free(line);
		}
	}
	if ((checktab(s)) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(s);
	return (0);
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
	if (ac == 2)
	{
		if ((checker_arg(av)) == -1)
			ft_putstr("Error\n");
		return (0);
	}
	else if ((checker(ac, av)) == -1)
		ft_putstr("Error\n");
	return (0);
}

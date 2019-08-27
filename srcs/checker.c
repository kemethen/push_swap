/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/08/27 18:39:15 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_stack(t_stack *s, char **av)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_tabsize(av) - 1;
	j = 0;
	k = 1;
	if (!(s->a = (int *)malloc(sizeof(int) * i)))
		return (-1);
	s->tabsize_a = i;
	s->tabsize_b = 0;
	s->write = 0;
	if (!(s->b = (int *)malloc(sizeof(int) * i)))
		return (-1);
	while (j < i)
	{
		s->a[j] = ft_atoi(av[k]);
		++j;
		++k;
	}
	return (1);
}

void	swap_b(t_stack *s)
{
	int		tmp;

	if (s->tabsize_b > 1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	if (s->write == 1)
		ft_putstr("sb\n");
}

void	swap_a(t_stack *s)
{
	int		tmp;

	if (s->tabsize_a > 1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
	if (s->write == 1 && s->both == 0)
		ft_putstr("sa\n");
}

int		checkline(char *line, t_stack *s)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
		return (0);
	else if (!(ft_strcmp(line, "sa")))
		swap_a(s);
	else if (!(ft_strcmp(line, "sb")) && s->tabsize_b > 0)
		swap_b(s);
	else if (!(ft_strcmp(line, "ss")))
		swap_both(s);
	else if (!(ft_strcmp(line, "pa")) && s->tabsize_b > 0)
		push_a(s);
	else if (!(ft_strcmp(line, "pb")) && s->tabsize_a > 0)
		push_b(s);
	else if (!(ft_strcmp(line, "ra")))
		rotate_a(s);
	else if (!(ft_strcmp(line, "rb")))
		rotate_b(s);
	checkline2(line, s);
	return (1);
}

void	checker(char **av)
{
	int		ret;
	int		check;
	char	*line;
	t_stack	*s;

	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack(s, av)) == -1)
	{
		ft_putstr("KO\n");
		return ;
	}
	ret = 1;
	check = 1;
	while (ret == 1 && check != 0)
	{
		ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			check = checkline(line, s);
			free(line);
			display_stacks(s);
		}
	}
	if (checktab(s))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free(s->a);
	free(s->b);
	free(s);
}

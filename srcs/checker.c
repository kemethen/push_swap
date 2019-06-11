/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:58:27 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/11 17:47:10 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		set_stack(t_stack *s, char **av)
{
	size_t	i;
	size_t	j;

	i = ft_tabsize(av);
	j = 0;
	if (!(s->a = (char **)malloc(sizeof(char *) * (sizeof(i)))))
		return (-1);
	while (j < i - 1)
	{
		s->a[j] = ft_strdup(av[j + 1]);
		++j;
	}
	s->a[j] = NULL;
	if (!(s->b = (char **)malloc(sizeof(char *) * (j + 1))))
		return (-1);
	i = 0;
	while (i < j)
		s->b[i++] = NULL;
	return (1);
}

void	swap_b(t_stack *s)
{
	char	*tmp;

	if (s->b[1] != NULL)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
}

void	swap_a(t_stack *s)
{
	char	*tmp;

	if (s->a[1] != NULL)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
}

int		checkline(char *line, t_stack *s)
{
	if (ft_strlen(line) <= 1 || ft_strlen(line) > 3)
		return (0);
	else if (line[0] == 's' && line[1] == 'a' && (!(line[2])))
		swap_a(s);
	else if (line[0] == 's' && line[1] == 'b' && (!(line[2])) && s->b[0])
		swap_b(s);
	else if (line[0] == 's' && line[1] == 's' && (!(line[2])))
	{
		swap_a(s);
		swap_b(s);
	}
	else if (line[0] == 'p' && line[1] == 'a' && (!(line[2])) && s->b[0])
		push_a(s);
	else if (line[0] == 'p' && line[1] == 'b' && (!(line[2])) && s->a[0])
		push_b(s);
	else if (line[0] == 'r' && line[1] == 'a' && (!(line[2])) && s->a[0])
		rotate_a(s);
	else if (line[0] == 'r' && line[1] == 'b' && (!(line[2])) && s->b[0])
		rotate_b(s);
	checkline2(line, s);
	return (1);
}

int		main(int ac, char **av)
{
	int		ret;
	int		check;
	char	*line;
	t_stack	*s;

	(void)ac;
	s = ft_memalloc(sizeof(t_stack));
	ft_bzero(s, sizeof(t_stack));
	if ((set_stack(s, av)) == -1)
	{
		ft_putstr("KO\n");
		return (0);
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
			ft_putstr("Stack A --------------------------------------------\n");
			ft_displaytab(s->a);
			ft_putstr("Stack B --------------------------------------------\n");
			ft_displaytab(s->b);
		}
	}
	ft_putstr("OK\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:45:19 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/11 17:47:11 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkline2(char *line, t_stack *s)
{
	if (line[0] == 'r' && line[1] == 'r' && (!(line[2])))
	{
		if (s->a[0])
			rotate_a(s);
		if (s->b[0])
			rotate_b(s);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && (!(line[3])))
	{
		if (s->a[0])
			reverse_rotate_a(s);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && (!(line[3])))
	{
		if (s->b[0])
			reverse_rotate_b(s);
	}
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && (!(line[3])))
	{
		if (s->a[0])
			rotate_a(s);
		if (s->b[0])
			rotate_b(s);
	}
}

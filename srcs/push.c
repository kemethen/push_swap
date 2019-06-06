/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:09:41 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/06 19:13:41 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filltab_b(t_stack *s, char **tmpa, char **tmpb)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < ft_tabsize(tmpb))
	{
		s->b[i] = ft_strdup(tmpb[j]);
		++i;
		++j;
	}
	i = 0;
	j = 1;
	while (j < ft_tabsize(tmpa))
	{
		s->a[i] = ft_strdup(tmpa[j]);
		++i;
		++j;
	}
}


void	filltab_a(t_stack *s, char **tmpa, char **tmpb)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < ft_tabsize(tmpa))
	{
		s->a[i] = ft_strdup(tmpa[j]);
		++i;
		++j;
	}
	i = 0;
	j = 1;
	while (j < ft_tabsize(tmpb))
	{
		s->b[i] = ft_strdup(tmpb[j]);
		++i;
		++j;
	}
}

void	push_b(t_stack *s)
{
	char	**tmpa;
	char	**tmpb;

	tmpa = ft_tabdup(s->a);
	tmpb = ft_tabdup(s->b);
	ft_putstr("check\n");
	ft_displaytab(s->a);
	ft_memdel((void **)s->a);
	ft_putstr("check2\n");
	ft_memdel((void **)s->b);
	ft_putstr("check3\n");
	s->a = ft_tabnew(ft_tabsize(tmpa) + 1);
	s->b = ft_tabnew(ft_tabsize(tmpb) + 1);
	s->b[0] = ft_strdup(tmpa[0]);
	filltab_b(s, tmpa, tmpb);
	ft_memdel((void **)tmpa);
	ft_memdel((void **)tmpb);
}

void	push_a(t_stack *s)
{
	char	**tmpa;
	char	**tmpb;

	tmpa = ft_tabdup(s->a);
	tmpb = ft_tabdup(s->b);
	ft_memdel((void **)s->a);
	ft_memdel((void **)s->b);
	s->a = ft_tabnew(ft_tabsize(tmpa) + 1);
	s->b = ft_tabnew(ft_tabsize(tmpb) + 1);
	s->a[0] = ft_strdup(tmpb[0]);
	filltab_a(s, tmpa, tmpb);
	ft_memdel((void **)tmpa);
	ft_memdel((void **)tmpb);
}

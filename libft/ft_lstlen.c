/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:12:16 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/16 12:22:25 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_tetri **list)
{
	int		cnt;

	cnt = 0;
	while ((*list)->next)
	{
		if ((*list)->next)
			*list = (*list)->next;
		cnt++;
	}
	while ((*list)->prev)
	{
		if ((*list)->prev)
			*list = (*list)->prev;
	}
	return (cnt);
}

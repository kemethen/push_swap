/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdupint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:08:09 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/12 16:11:36 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_tabdupint(int *t1, int size)
{
	int		*t2;
	int		i;

	i = 0;
	if (!(t2 = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		t2[i] = t1[i];
		i++;
	}
	return (t2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:49:15 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/06 18:51:14 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t size)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ft_bzero(*tab, size + 1);
	tab[size] = NULL;
	return (tab);
}

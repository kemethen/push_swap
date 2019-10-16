/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:45:20 by kemethen          #+#    #+#             */
/*   Updated: 2018/11/13 10:37:12 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < size)
	{
		j = 0;
		while (str[i] == to_find[j] && i < size)
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i - j);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}

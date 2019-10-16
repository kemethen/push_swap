/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:55:50 by kemethen          #+#    #+#             */
/*   Updated: 2018/11/13 12:36:31 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	j = ft_strlen(dest);
	i = 0;
	src_len = 0;
	while (src[i] && j + i + 1 < size)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	src_len = ft_strlen(src);
	if (size < j)
		return (size + src_len);
	return (j + src_len);
}

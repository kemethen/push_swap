/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:15:29 by kemethen          #+#    #+#             */
/*   Updated: 2019/02/26 10:17:31 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t size)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str) + size);
	tmp = ft_strcpy(tmp, str);
	free(str);
	return (tmp);
}

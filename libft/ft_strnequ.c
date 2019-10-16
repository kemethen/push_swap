/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:24:57 by kemethen          #+#    #+#             */
/*   Updated: 2018/11/14 15:25:57 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
		return (0);
	return (!(ft_strncmp(s1, s2, n)));
}

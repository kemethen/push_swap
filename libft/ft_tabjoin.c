/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:03:50 by kemethen          #+#    #+#             */
/*   Updated: 2018/11/21 14:15:13 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabjoin(const char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (tab[i] != NULL)
	{
		len = len + ft_strlen(tab[i]) - 1;
		i++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
			str[len++] = tab[i][j++];
		i++;
	}
	str[len] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:38:21 by kemethen          #+#    #+#             */
/*   Updated: 2019/06/11 11:09:00 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **t1)
{
	char	**t2;
	int		i;
	int		j;

	i = ft_tabsize(t1);
	j = 0;
	if (!(t2 = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		t2[j] = ft_strdup(t1[j]);
		++j;
	}
	t2[j] = NULL;
	return (t2);
}

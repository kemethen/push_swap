/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaytabint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:07:49 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/09 14:43:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_displaytabint(int *tab, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	while (i < size)
	{
		str = ft_itoa(tab[i]);
		ft_printf("|%s|", str);
		free(str);
		++i;
	}
	ft_putchar('\n');
}

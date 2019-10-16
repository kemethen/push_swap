/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:31:25 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 11:55:29 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		negatif;

	i = 0;
	nbr = 0;
	negatif = 0;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == 45)
		negatif = 1;
	if (str[i] == 45 && (str[i + 1] >= 48 && str[i + 1] <= 57))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nbr = nbr * 10 + str[i] - 48;
		if (nbr > 2147483647 || nbr <= -2147483649)
			return (-2147483645);
		i++;
	}
	if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		return (-2147483645);
	if (negatif == 1)
		return (-nbr);
	return (nbr);
}

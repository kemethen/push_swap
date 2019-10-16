/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:27:12 by kemethen          #+#    #+#             */
/*   Updated: 2019/04/23 16:12:02 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_power(long long a, long long b)
{
	char			*str;
	long	long	result;

	result = a;
	while (b != 0)
	{
		result = result * a;
		b--;
	}
	str = ft_lltoa(result);
	ft_putstr(str);
	free(str);
}

static void	ft_div(long long a, long long b, char op)
{
	char			*str;
	long	long	result;

	if (op == '/')
	{
		if (b == 0)
			ft_putstr("Error\nDivision by zero.\n");
		else
			result = a / b;
	}
	else if (op == '%')
	{
		if (b == 0)
			ft_putstr("Error\nModulo by zero.\n");
		else
			ft_putnbr(a % b);
	}
	if (b != 0)
	{
		str = ft_lltoa(result);
		ft_putstr(str);
		free(str);
	}
}

static void	ft_add_sous(long long a, long long b, char op)
{
	long long		result;
	char			*str;

	result = 0;
	if (op == '+')
		result = a + b;
	else
		result = a - b;
	str = ft_lltoa(result);
	ft_putstr(str);
	free(str);
}

void		ft_doop(long long a, char op, long long b)
{
	if (op == '+' || op == '-')
		ft_add_sous(a, b, op);
	else if (op == '*')
		ft_putnbr(a * b);
	else if (op == '/' || op == '%')
		ft_div(a, b, op);
	else if (op == '^')
		ft_power(a, b);
	else if (op != '+' && op != '-' && op != '*' && op != '/'
			&& op != '%' && op != '^')
		ft_putstr("Error\nWrong format of operator");
	else
		ft_putstr("Error\nFormat of argument : number ''operator'' number");
	ft_putchar('\n');
}

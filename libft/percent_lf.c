/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_lf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:15:59 by kemethen          #+#    #+#             */
/*   Updated: 2019/05/29 18:05:21 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	link_float(t_var *v, double n)
{
	v->str = ft_strjoin(v->tmp, ".");
	ft_memdel((void **)&v->tmp);
	v->str = joinfree(v->str, v->tmp2);
	if (v->neg != 0)
	{
		v->tmp = ft_strdup("-");
		v->str = joinfree(v->tmp, v->str);
	}
	if (n == 0 && v->prc == 0)
	{
		ft_memdel((void **)&v->str);
		v->str = ft_strdup("0.000000");
	}
	else if (n == 0 && v->prc != 0)
	{
		ft_memdel((void **)&v->str);
		v->str = ft_strndup("0.000000000000000", v->prc + 2);
	}
}

void	percent_lfloat(long double n, t_var *v, char c)
{
	double		test;
	size_t		cnt;
	size_t		len;

	cnt = 0;
	if (n < 0)
	{
		v->neg = 1;
		n = n * -1;
	}
	v->tmp = ft_ultoa((long long)n);
	test = n - (long long)n;
	while (test - (unsigned long long)test > 0)
	{
		test *= 10;
		++cnt;
	}
	v->tmp2 = ft_ultoa(test);
	len = ft_strlen(v->tmp2);
	link_float(v, n);
	len = ft_strlen(v->str);
	pr_or_wd_float(v, len, c);
	v->j = v->i + 3;
}

void	checkfloat(t_var *v)
{
	int		len;
	int		mts;

	len = ft_strlen(v->str);
	mts = len - v->lpnt - 1;
	if (mts < 6 && v->prc == 0 && v->lpnt != len && v->str[len - 1] != '.')
	{
		v->tmp = ft_strdup(v->str);
		v->tmp2 = ft_strndup("00000", 6 - mts);
		ft_memdel((void **)&v->str);
		v->str = joinfree(v->tmp, v->tmp2);
	}
	if (mts > 6 && v->prc == 0)
		v->str[v->lpnt + 7] = '\0';
	if (v->width != 0 && v->prc != 0 && v->str[0] != '0')
		pr_and_wd_float(v);
	else if (v->width != 0)
		width(v);
	else if (v->prc != 0 && v->str[0] != '0')
	{
		prc_float(v);
		fillbuff(v);
	}
	else
		fillbuff(v);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:52:14 by kemethen          #+#    #+#             */
/*   Updated: 2019/05/29 18:18:08 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prc_float(t_var *v)
{
	int		i;

	i = 0;
	v->len = ft_strlen(v->str);
	if (v->lpnt <= 15)
	{
		v->tmp = ft_strndup(v->str, v->prc + v->lpnt + 2);
		ft_memdel((void **)&v->str);
		v->len = ft_strlen(v->tmp);
		if (v->prc < 15)
			v->tmp[ft_strlen(v->tmp) - 1] = '\0';
		v->str = ft_strdup(v->tmp);
		ft_memdel((void **)&v->tmp);
	}
	if (v->prc + v->lpnt > 16)
	{
		v->tmp = ft_strnew(v->prc);
		while (v->len + i < v->prc + v->lpnt + 1)
			v->tmp[i++] = '0';
		v->str = joinfree(v->str, v->tmp);
	}
}

void	pr_and_wd_float(t_var *v)
{
	prc_float(v);
	if (v->width > v->prc)
		width(v);
	else
		fillbuff(v);
}

void	pr_or_wd_float(t_var *v, size_t len, char c)
{
	while (v->str[v->lpnt] != '.')
		v->lpnt++;
	if (v->dot != 0 && v->prc == 0)
	{
		v->tmp = ft_strsub(v->str, 0, v->lpnt);
		ft_memdel((void **)&v->str);
		v->str = v->tmp;
	}
	if (v->prc == 0 && v->dot != 0 && c == 'a')
	{
		v->tmp = ft_strjoin(v->str, ".");
		ft_memdel((void **)&v->str);
		v->str = v->tmp;
	}
	else if (v->prc == 0 && v->str[0] != '0' && v->dot == 0)
	{
		v->tmp = ft_strsub(v->str, 0, v->lpnt + 8);
		ft_memdel((void **)&v->str);
		v->str = ft_strdup(v->tmp);
		ft_memdel((void **)&v->tmp);
		len = ft_strlen(v->str);
		if (v->str[v->lpnt + 1] != v->str[len - 1])
			v->str[len - 1] = '\0';
	}
	checkfloat(v);
}

void	percent_float(double n, t_var *v, char c)
{
	double	test;
	size_t	cnt;
	size_t	len;

	cnt = 0;
	if (n < 0)
	{
		v->neg = 1;
		n = n * -1;
	}
	v->tmp = ft_lltoa((long long)n);
	test = n - (long long)n;
	while (test - (unsigned long long)test != 0)
	{
		test *= 10;
		++cnt;
	}
	v->tmp2 = ft_lltoa(test);
	len = ft_strlen(v->tmp2);
	link_float(v, n);
	len = ft_strlen(v->str);
	pr_or_wd_float(v, len, c);
	v->j = v->i + 2;
}

void	percent_f(const char *str, va_list ap, t_var *v)
{
	if (str[v->i + 1] == 'f')
		percent_float(va_arg(ap, double), v, 'b');
	if (str[v->i + 1] == 'l')
	{
		if (str[v->i + 2] == 'f')
		{
			percent_float(va_arg(ap, double), v, 'b');
			v->j++;
		}
	}
	if (str[v->i + 1] == 'L')
	{
		if (str[v->i + 2] == 'f')
			percent_lfloat(va_arg(ap, long double), v, 'b');
	}
}

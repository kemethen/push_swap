/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:21:55 by kemethen          #+#    #+#             */
/*   Updated: 2019/05/29 15:03:40 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printf_return(t_var *v)
{
	v->tab[v->tabsize] = -1;
	v->tabsize = 0;
	if (v->buff)
		return (len_buff(v) + v->tabsize);
	else
		return (len_str(v) + v->tabsize);
}

size_t	len_buff(t_var *v)
{
	if (v->bzerocheck == 1)
	{
		v->i = 0;
		while (v->buff[v->i] != '\0')
		{
			while ((int)v->i < v->tab[v->tabsize] && v->buff[v->i])
				ft_putchar(v->buff[v->i++]);
			if (v->tab[v->tabsize] != -1)
			{
				ft_putchar('\0');
				v->tabsize++;
			}
			while (v->tab[v->tabsize] == -1 && v->i < ft_strlen(v->buff))
				ft_putchar(v->buff[v->i++]);
		}
	}
	else
		ft_putstr(v->buff);
	v->len = ft_strlen(v->buff);
	ft_memdel((void **)&v->buff);
	return (v->len);
}

size_t	len_str(t_var *v)
{
	if (v->i == 0)
		return (0);
	if (v->bzerocheck == 1)
	{
		v->i = 0;
		if (v->bzero == 0)
			ft_putchar('\0');
		while (v->i < v->bzero - v->percent)
			ft_putchar(v->buff[v->i++]);
		if (v->bzero != 0)
			ft_putchar('\0');
		while (v->i < ft_strlen(v->buff))
			ft_putchar(v->buff[v->i++]);
		v->bzero = 1;
	}
	else
		ft_putstr(v->str);
	v->len = ft_strlen(v->str);
	ft_memdel((void **)&v->str);
	return (v->len);
}

void	reset_v(t_var *v)
{
	if (v->width != 0 && v->bzero == 1)
	{
		v->tmp = ft_itoa(v->width);
		v->percent = ft_strlen(v->tmp) + 1;
		ft_memdel((void **)&v->tmp);
	}
	if (v->bzero == 1)
	{
		if (v->buff)
			v->tab[v->tabsize] = ft_strlen(v->buff);
		else if (v->str)
			v->tab[v->tabsize] = ft_strlen(v->str);
		if (v->width != 0 && v->mns != 0)
			v->tab[v->tabsize] = v->tab[v->tabsize] - v->width + 1;
		v->bzerocheck = 1;
		v->tabsize++;
	}
	v_zero(v);
}

char	*joinfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (tmp);
}

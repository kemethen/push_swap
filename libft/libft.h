/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:02:24 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/13 11:46:59 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10999

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_var
{
	size_t	i;
	size_t	j;
	size_t	bzero;
	size_t	bzerocheck;
	size_t	percent;
	size_t	tabsize;
	int		lpnt;
	int		width;
	int		prc;
	int		len;
	int		len2;
	int		size;
	int		size2;
	int		dot;
	int		neg;
	int		mns;
	int		plus;
	int		space;
	int		nbr;
	int		zero;
	int		d;
	int		iszero;
	int		*tab;
	char	*str;
	char	*length;
	char	*tmp;
	char	*tmp2;
	char	*prwd;
	char	*buff;
}				t_var;

typedef struct	s_case
{
	short	x;
	short	y;
}				t_case;
typedef struct	s_tetri
{
	t_case			a;
	t_case			b;
	t_case			c;
	t_case			d;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}				t_tetri;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_printf(const char *str, ...);
void			fillbuff(t_var *v);
void			reset_v(t_var *v);
char			*joinfree(char *s1, char *s2);
void			iszero(t_var *v, char *str, char c);
size_t			percent_c(t_var *v, char c, size_t i, size_t j);
size_t			percent_s(t_var *v, char *str, size_t i, size_t j);
void			percent_p(va_list ap, t_var *v);
void			percent_space(const char *str, t_var *v);
void			percent_sign(const char *str, t_var *v);
void			percent_dot(const char *str, t_var *v);
void			precision(t_var *v);
void			vplus(t_var *v);
void			percent_nbr(const char *str, t_var *v);
void			width(t_var *v);
void			pr_or_wd(t_var *v);
void			pr_or_wd_ltr(t_var *v);
void			pr_and_wd(t_var *v);
void			pr_and_wd_neg(t_var *v);
void			pr_or_wd_sharp(t_var *v, char c);
void			pr_and_wd_sharp(t_var *v, char c);
void			wd_prc_neg(t_var *v);
void			percent_d_and_i(int nb, t_var *v);
void			percent_ld_and_li(long long nb, t_var *v);
void			percent_u(unsigned int value, t_var *v);
void			percent_lu(unsigned long value, t_var *v, const char *str);
void			percent_o(unsigned int value, t_var *v);
void			percent_lo(unsigned long value, t_var *v);
size_t			percent_sharp(const char *str, va_list ap, t_var *v);
void			percent_sharp_o(unsigned int value, t_var *v);
void			percent_sharp_lo(unsigned long long value, t_var *v);
size_t			mbase_eight(unsigned int n);
size_t			mbase_eight_ll(unsigned long n);
int				msize_hexa_int(unsigned int n);
size_t			msize_hexa_ul(unsigned long n);
char			*hexa_pointer(unsigned long value);
void			hexa_up(unsigned int value, t_var *v);
void			hexa_up_sharp(unsigned int value, t_var *v);
void			hexa_up_lsharp(unsigned long value, t_var *v);
void			precision_sharp_up(t_var *v);
void			width_sharp_up(t_var *v);
void			hexa_low(unsigned int value, t_var *v);
void			hexa_low_sharp(unsigned long value, t_var *v);
void			hexa_low_lsharp(unsigned long value, t_var *v);
void			precision_sharp_low(t_var *v);
void			width_sharp_low(t_var *v);
void			percent_f(const char *str, va_list ap, t_var *v);
void			percent_float(double n, t_var *v, char c);
void			percent_lfloat(long double n, t_var *v, char c);
void			link_float(t_var *v, double n);
void			pr_or_wd_float(t_var *v, size_t len, char c);
void			checkfloat(t_var *v);
void			prc_float(t_var *v);
void			pr_and_wd_float(t_var *v);
void			percent_percent(t_var *v);
size_t			percent_h(const char *str, va_list ap, t_var *v);
size_t			percent_l(char const *str, va_list ap, t_var *v);
void			hexa_low_ul(unsigned long value, t_var *v);
void			hexa_up_ul(unsigned long value, t_var *v);
void			v_zero(t_var *v);
size_t			printf_return(t_var *v);
size_t			len_buff(t_var *v);
size_t			len_str(t_var *v);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char	*dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(const void *content, size_t size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *st, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstpush(t_list **alst, t_list *new);
void			ft_doop(long long a, char op, long long b);
void			ft_printlist(const t_list *list);
void			ft_displaytab(char **tab);
char			*ft_tabjoin(const char **tab);
char			*ft_strndup(char *s1, int n);
int				ft_lstlen(t_tetri **list);
char			*ft_strrev(char *str);
void			ft_putnbru(unsigned int n);
void			ft_putnbrs(short n);
void			ft_putnbrus(unsigned short n);
void			ft_putnbruc(unsigned char c);
void			ft_putnbrc(char c);
void			ft_putnbrl(long int n);
void			ft_putnbrul(unsigned long n);
void			ft_putnbrll(long long int n);
char			*ft_realloc(char *str, size_t size);
char			*ft_ultoa(unsigned long n);
char			*ft_uitoa(unsigned int n);
char			*ft_lltoa(long long n);
size_t			ft_tabsize(char **tab);
char			**ft_tabdup(char **t1);
char			**ft_tabnew(size_t size);
void			ft_freetab(char **tab);
void			ft_displaytabint(int *tab, size_t size);
int				*ft_tabdupint(int *t1, int size);
int				get_next_line(int const fd, char **line);

#endif

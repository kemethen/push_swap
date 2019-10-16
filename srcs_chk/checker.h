/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:15:23 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/15 12:21:48 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	int			*a;
	size_t		tabsize_a;
	int			*b;
	size_t		tabsize_b;
	int			write;
	int			both;
	int			ret;
	int			check;
	int			max;
	int			push_swap;
	int			visual;
	int			cnt;
	int			top;
	int			bot;
}				t_stack;

int				checktab(t_stack *s);
int				checker(int ac, char **av);
int				checkline2(char *line, t_stack *s);
int				checkdupe(t_stack *s);
int				get_next_line(int const fd, char **line);
void			swap_a(t_stack *s);
void			swap_b(t_stack *s);
void			push_a(t_stack *s);
void			push_b(t_stack *s);
void			rotate_a(t_stack *s);
void			rotate_b(t_stack *s);
void			reverse_rotate_a(t_stack *s);
void			reverse_rotate_b(t_stack *s);
int				set_stack(t_stack *s, int ac, char **av);
int				push_swap(int ac, char **av);
void			sort_a(t_stack *s);
void			swap_both(t_stack *s);
void			rotate(t_stack *s);
void			reverse_rotate(t_stack *s);
void			display_stacks(t_stack *s);
void			reverse_rotate_both(t_stack *s);
int				last_three(t_stack *s);
int				find_max(int *tab, int size);
int				find_max_index(int *tab, int size);
int				find_med_index(int *tab, int med);
int				number_min(int *tab, int size);
int				bot_push(int *tab, int size, int med);
int				checktab(t_stack *s);
void			rotate_both(t_stack *s);
void			free_stack(t_stack *s);
void			fill_a(t_stack *s);
void			fill_b(t_stack *s);
int				fill_stack(t_stack *s, int ac, char **av);
int				checkline(char *line, t_stack *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:15:23 by kemethen          #+#    #+#             */
/*   Updated: 2019/10/16 17:20:57 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	size_t		i;
}				t_stack;

void			display_stacks(t_stack *s);
void			push_swap_three(t_stack *s);
int				checktab_p(t_stack *s);
int				checker_p(int ac, char **av);
int				checkline2_p(char *line, t_stack *s);
int				checkdupe_p(t_stack *s);
void			swap_a_p(t_stack *s);
void			swap_b_p(t_stack *s);
void			push_a_p(t_stack *s);
void			push_b_p(t_stack *s);
void			rotate_a_p(t_stack *s);
void			rotate_b_p(t_stack *s);
void			reverse_rotate_a_p(t_stack *s);
void			reverse_rotate_b_p(t_stack *s);
void			split_stack(t_stack *s);
void			split_stack2(t_stack *s, int top, int bot, int med);
int				set_stack_p(t_stack *s, int ac, char **av);
int				push_swap_p(int ac, char **av);
void			sort_a_p(t_stack *s);
void			swap_both_p(t_stack *s);
void			rotate_p(t_stack *s);
void			reverse_rotate_p(t_stack *s);
void			display_stacks_p(t_stack *s);
void			reverse_rotate_both_p(t_stack *s);
void			to_bottom_max(t_stack *s, int max);
void			to_top_max(t_stack *s, int max);
int				last_three_p(t_stack *s);
int				find_max_p(int *tab, int size);
int				find_max_index_p(int *tab, int size);
int				find_med_index_p(int *tab, int med);
int				median(int *t1, int size);
int				number_min_p(int *tab, int size);
void			sort_b(t_stack *s, int top, int bot, int med);
int				top_push(int *tab, int med);
int				bot_push_p(int *tab, int size, int med);
int				checktab_p(t_stack *s);
void			rotate_both_p(t_stack *s);
void			free_stack_p(t_stack *s);
void			sort(t_stack *s);
void			big_list(t_stack *s);
void			fill_a_p(t_stack *s);
void			fill_b_p(t_stack *s);
void			push_swap_four(t_stack *s);
int				fill_stack_p(t_stack *s, int ac, char **av);
int				set_stack_arg(t_stack *s, int ac, char **av);

#endif

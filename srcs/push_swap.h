/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:15:23 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/18 18:10:08 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		main(int ac, char **av);
void	checker(char **av);
void	checkline2(char *line, t_stack *s);
int		get_next_line(int const fd, char **line);
void	swap_a(t_stack *s);
void	swap_b(t_stack *s);
void	push_a(t_stack *s);
void	push_b(t_stack *s);
void	rotate_a(t_stack *s);
void	rotate_b(t_stack *s);
void	reverse_rotate_a(t_stack *s);
void	reverse_rotate_b(t_stack *s);
int		checktab(t_stack *s);
int		set_stack(t_stack *s, char **av);
int		push_swap(char **av);
void	quicksort(t_stack *s);
int		median(int *t1, int size);
void	swap_both(t_stack *s);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	display_stacks(t_stack *s);
void	reverse_rotate_both(t_stack *s);
void	to_bottom_max(t_stack *s, int max);
void	to_top_max(t_stack *s, int max);
int		last_three(t_stack *s);
int		find_max(int *tab, int size);

#endif

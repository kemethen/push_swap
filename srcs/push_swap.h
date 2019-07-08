/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:15:23 by kemethen          #+#    #+#             */
/*   Updated: 2019/07/08 16:42:43 by kemethen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		main(int ac, char **av);
int		main2(int ac, char **av);
void	checker(char **av);
void	checkline2(char *line, t_stack *s);
int		get_next_line(int const fd, char **line);
void	swap_a(t_stack *s);
void	push_a(t_stack *s);
void	push_b(t_stack *s);
void	rotate_a(t_stack *s);
void	rotate_b(t_stack *s);
void	reverse_rotate_a(t_stack *s);
void	reverse_rotate_b(t_stack *s);
int		checktab(t_stack *s);
int		set_stack(t_stack *s, char **av);
int		push_swap(char **av);
void	to_bottom(t_stack *s, int i);
void	to_top(t_stack *s, int i);
void	quicksort(t_stack *s);
int		median(int *t1, int size);

#endif

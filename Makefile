# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 12:14:06 by kemethen          #+#    #+#              #
#    Updated: 2019/10/12 18:05:27 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
NAME2	= push_swap
CC		= gcc
CFLAGS += -Wall -Wextra -Werror
SRCDIR	= srcs
OBJDIR	= obj
LIBDIR	= libft
INCDIR	= $(LIBDIR)

HEAD	= $(SRCDIR)/push_swap.h

SRC		=	checker.c \
		checkline.c \
		get_next_line.c \
		main.c \
		move_max.c \
		push.c \
		rotate.c

SRC2	= big_list.c \
		checker.c \
		checkline.c \
		get_next_line.c \
		move_max.c \
		move.c \
		push.c \
		pushswap.c \
		rotate.c \
		sort.c \
		split_stack.c 

CFLAGS += -I$(INCDIR)
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJ2	= $(addprefix $(OBJDIR)/,$(SRC2:.c=.o))
LIB		= $(LIBDIR)/libft.a

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME) $(NAME2)

checker: $(NAME)

push_swap: $(NAME2)

$(NAME): $(LIB) $(OBJ)
	@echo "\n$(GREEN)Compiling\t$(YELLOW)$@ $(WHITE)with $^"
	@$(CC) -o $@ $^
	@echo "$@  \t[$(GREEN)✓$(WHITE)]"

$(NAME2): $(LIB) $(OBJ2)
	@echo "\n$(GREEN)Compiling\t$(YELLOW)$@ $(WHITE)with $^"
	@$(CC) -o $@ $^
	@echo "$@  \t[$(GREEN)✓$(WHITE)]"

$(LIB):
	@make -j3 -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@make -C $(LIBDIR) clean
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)"
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C $(LIBDIR) fclean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME) & $(NAME2)\n"
	@rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

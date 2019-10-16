# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 12:14:06 by kemethen          #+#    #+#              #
#    Updated: 2019/10/15 18:25:05 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
NAME2	= push_swap
CC		= gcc
CFLAGS  = -Wall -Wextra -Werror -g3
SRCDIR	= srcs_chk
SRCDIR2 = srcs_pshswp
OBJDIR	= obj_chk
OBJDIR2	= obj_pshswp
LIBDIR	= libft
INCDIR	= $(LIBDIR)

HEAD	= $(SRCDIR)/checker.h
HEAD2	= $(SRCDIR2)/push_swap.h

SRC		=	checker.c \
		checkline.c \
		main.c \
		move_max.c \
		push.c \
		rotate.c

SRC2	= big_list.c \
		checker_p.c \
		checkline_p.c \
		move_max_p.c \
		move.c \
		push_p.c \
		pushswap.c \
		rotate_p.c \
		sort.c \
		split_stack.c 

CFLAGS += -I$(INCDIR)
OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJ2	= $(addprefix $(OBJDIR2)/,$(SRC2:.c=.o))
LIB		= $(LIBDIR)/libft.a

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: checker push_swap

$(NAME): $(LIB) $(OBJ)
	@echo "\n$(GREEN)Compiling\t$(YELLOW)$@ $(WHITE)with $^"
	@$(CC) -o $@ $^
	@echo "$@  \t[$(GREEN)✓$(WHITE)]"

$(NAME2): $(LIB) $(OBJ2)
	@echo "\n$(GREEN)Compiling\t$(YELLOW)$@ $(WHITE)with $^"
	@$(CC) -o $@ $^
	@echo "$@  \t[$(GREEN)✓$(WHITE)]"

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

$(OBJDIR2)/%.o: $(SRCDIR2)/%.c $(HEAD2)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ2): | $(OBJDIR2)

$(OBJDIR2):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@make -C $(LIBDIR) clean
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)' & '$(OBJDIR2)'"
	@rm -rf $(OBJDIR) $(OBJDIR2)

fclean: clean
	@make -C $(LIBDIR) fclean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME) & $(NAME2)\n"
	@rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

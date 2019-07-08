# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 12:14:06 by kemethen          #+#    #+#              #
#    Updated: 2019/07/08 16:24:59 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
NAME2	= push_swap
CC		= gcc
CFLAGS += -Wall -Wextra -Werror
SRCDIR	= srcs
SRCDIR2	= srcs2
OBJDIR	= obj
OBJDIR2	= obj2
LIBDIR	= libft
INCDIR	= $(LIBDIR)

HEAD	= $(SRCDIR)/push_swap.h

SRC		= checker.c \
		checkline.c \
		get_next_line.c \
		main2.c \
		push.c \
		rotate.c 

SRC2	= main.c \
		move_median.c \
		push_swap.c 

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

all: $(NAME) $(NAME2)

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

clean:
	@make -C $(LIBDIR) clean
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR) & $(OBJDIR2)'"
	@rm -rf $(OBJDIR) $(OBJDIR2)

fclean: clean
	@make -C $(LIBDIR) fclean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIB)

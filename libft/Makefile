# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kemethen <kemethen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 12:07:01 by kemethen          #+#    #+#              #
#    Updated: 2019/10/13 10:27:11 by kemethen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= obj
AR		= ar
ARFLAGS	= -rcs
HEAD	= libft.h

SRC		= ft_atoi.c \
	ft_bzero.c \
	ft_displaytab.c \
	ft_displaytabint.c \
	ft_doop.c \
	ft_freetab.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lltoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlen.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpush.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_printlist.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putnbrc.c \
	ft_putnbrl.c \
	ft_putnbrll.c \
	ft_putnbrs.c \
	ft_putnbru.c \
	ft_putnbruc.c \
	ft_putnbrul.c \
	ft_putnbrus.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_realloc.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tabdup.c \
	ft_tabdupint.c \
	ft_tabjoin.c \
	ft_tabnew.c \
	ft_tabsize.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_uitoa.c \
	ft_ultoa.c \
	get_next_line.c \
	percent_csdi.c \
	percent_f.c \
	percent_h.c \
	percent_l.c \
	percent_ldlilolu.c \
	percent_lf.c \
	percent_lxu.c \
	percent_p_and_o.c \
	percent_sharp.c \
	percent_sharp_lo_and_lx.c \
	percent_sharp_o_and_x.c \
	percent_sign_nbr.c \
	percent_x.c \
	pr_and_wd.c \
	precision.c \
	printf_return.c \
	printf_return.c \
	width.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

GREEN	= \033[1;32m
PURPLE	= \033[1;35m
RED		= \033[1;31m
YELLOW	= \033[1;33m
BLUE	= \033[1;36m
WHITE	= \033[1;37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(YELLOW)$@ \t$(PURPLE)must be updated with $(WHITE)$(notdir $?)"
	@echo "$(PURPLE)Updating\t$(YELLOW)$@"
	@$(AR) $(ARFLAGS) $@ $?
	@echo "$@ :\t$(GREEN)Indexed / Up to date"

$(OBJDIR)/%.o: %.c $(HEAD)
	@echo "$(PURPLE)Updating\t$(WHITE)$@"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@echo "$(GREEN)Creating\t$(WHITE)directory $(BLUE)'$@'\n"
	@mkdir $@

clean:
	@echo "$(RED)Deleting\t$(WHITE)directory $(BLUE)'$(OBJDIR)' in libft"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Deleting\t$(YELLOW)$(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhakh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 16:10:41 by rhakh             #+#    #+#              #
#    Updated: 2016/12/23 20:05:43 by sbondar          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fillit
SRC =	ft_file_open.c \
		ft_get_figures.c \
		ft_print.c \
		ft_get_cords.c \
		ft_fillit.c \
		ft_figure_ops.c \
		ft_figure_check.c \
		ft_strsplit.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putendl.c \
		main.c \

SRCDIR = ./src/

OBJDIR = ./obj/

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


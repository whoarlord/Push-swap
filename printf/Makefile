# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 12:40:51 by iarrien-          #+#    #+#              #
#    Updated: 2026/02/11 13:10:35 by iarrien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc
CFLAGS= -I.
LIB= ar rcs

SRC=ft_printf.c ft_print_formats.c get_next_line.c get_next_line_utils.c
OBJ=$(SRC:.c=.o)
HEADERS=./libft/libft.h ft_printf.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re makelibft
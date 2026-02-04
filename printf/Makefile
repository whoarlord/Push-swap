# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 12:40:51 by iarrien-          #+#    #+#              #
#    Updated: 2026/01/30 11:37:34 by iarrien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc
CFLAGS= -Wall -Werror -Wextra -I.
LIB= ar rcs

SRC=ft_printf.c ft_print_formats.c
OBJ=$(SRC:.c=.o)
HEADERS=./libft/libft.h ft_printf.h

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
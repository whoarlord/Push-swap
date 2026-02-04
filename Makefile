# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 13:07:48 by iarrien-          #+#    #+#              #
#    Updated: 2026/02/04 18:34:04 by iarrien-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out

CC=cc
CFLAGS= -Wall -Werror -Wextra -I. -g
LIB=libftprintf.a

SRC=main.c ft_allocs.c ft_frees.c
OBJ=$(SRC:.c=.o)
HEADERS=./printf/ft_printf.h push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(MAKE) -C ./printf
	cp ./printf/libftprintf.a $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./printf

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	$(MAKE) fclean -C ./printf

re: fclean all

.PHONY: all clean fclean re
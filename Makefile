# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 13:07:48 by iarrien-          #+#    #+#              #
#    Updated: 2026/02/10 16:09:44 by shierro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=a.out

CC=cc
CFLAGS= -Wall -Werror -Wextra -I. -g
LIB=libftprintf.a

SRC=main.c ft_allocs.c ft_frees.c ft_swap.c ft_validations.c ft_push.c ft_rotate.c ft_rotate_reverse.c\
	ft_utils.c ft_bubble.c ft_radix_sort.c ft_manipulate_arrays.c ft_borders.c ft_turk_sort.c ft_turk_utils.c ft_bench.c ft_merge_sort.c
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
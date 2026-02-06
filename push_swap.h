/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:26:15 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/06 17:08:24 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"

typedef struct s_manager
{
	int		algorithm;
	int		bench;
	int		error;
	char	**numbers;
}			t_manager;

typedef struct s_stack
{
	int		*nums;
	int		size;
	char	type;
	int		biggest;
	int		smallest;
}			t_stack;

typedef struct s_borders
{
	int		min;
	int		minindex;
	int		max;
	int		maxindex;
}			t_borders;

typedef struct s_moves
{
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rr;
	int		rrr;
}			t_moves;

void		ft_printmoves(t_moves *moves);
void		ft_print_stack(t_stack *stack);
void		*ft_init_stacks(int size, char **numstr, t_stack *a, t_stack *b);
t_manager	*ft_fill_manager(int argc, char *argv[]);
char		*ft_swap(t_stack *stack);
char		*ft_swap_both(t_stack *a, t_stack *b);
char		*ft_push(t_stack *dest, t_stack *src);
char		*ft_rotate(t_stack *stack);
char		*ft_rotate_both(t_stack *a, t_stack *b);
char		*ft_rotate_reverse(t_stack *stack);
char		*ft_rotate_reverse_both(t_stack *a, t_stack *b);
void		ft_free_manager(t_manager *manager);
void		ft_free_stack(t_stack *stack);
void		ft_free_all(t_manager *manager, t_stack *a, t_stack *b);
int			ft_validate_numinput(char **numstr);
int			ft_check_doubles(int *nums, int size);
float		compute_disorder(t_stack *a);
void		ft_bubble_sort(t_stack *a);
void		ft_selection_sort(t_stack *a, t_stack *b);
t_borders	*ft_get_borders(t_stack *a, t_borders *borders);
void		ft_min_closer_to_start(t_stack *a, t_stack *b, t_borders *borders);
void		ft_max_closer_to_end(t_stack *a, t_stack *b, t_borders *borders);
void		ft_max_closer_to_start(t_stack *a, t_stack *b, t_borders *borders);
void		ft_min_closer_to_end(t_stack *a, t_stack *b, t_borders *borders);
void		ft_interpolation_sort(t_stack *a, t_stack *b, t_manager *manager);
void		ft_adjust_b_position(int n, t_stack *b);
void		ft_putmaxfirst(t_stack *stack, int max);
void		ft_turk(t_stack *a, t_stack *b, t_manager *manager);
void		ft_find_cheapest_moves(t_stack *a, t_stack *b, t_moves *mmoves);
int			ft_calculate_moves(t_stack *a, t_stack *b, int index,
				t_moves *moves);
int			ft_find_target_index(int num, t_stack *stack);
t_stack		*ft_set_first_extremes(t_stack *stack);
void		ft_initmoves(t_moves *moves);

#endif

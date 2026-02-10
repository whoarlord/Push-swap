/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:26:15 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/10 16:20:11 by shierro          ###   ########.fr       */
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
	int		*index;
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
	int		ss;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rr;
	int		rrr;
	int		bench;
	int		pa;
	int		pb;
	int		all;
}			t_moves;

typedef struct s_indexed_num
{
	int		num;
	int		index;
}			t_indexed_num;

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
void		ft_free_all(t_manager *manager, t_stack *a, t_stack *b, int error);
int			ft_validate_numinput(char **numstr);
int			ft_check_doubles(int *nums, int size);
float		compute_disorder(t_stack *a);
float		compute_disorder_reverse(t_stack *a);
void		ft_bubble_sort(t_stack *a);
void		ft_selection_sort(t_stack *a, t_stack *b);
void		ft_radix_sort(t_stack *a, t_stack *b, t_manager *manager);
void		ft_push_array(int *dest, int *src, int size_dest, int size_src);
void		ft_rotate_reverse_array(int *array, int size);
void		ft_rotate_array(int *array, int size);
int			ft_manage_array(int *array, t_stack *dest, t_stack *origin,
				t_moves *bench);
t_borders	*ft_get_borders(t_stack *a, t_borders *borders);
void		ft_adjust_b_position(int n, t_stack *b);
void		ft_putmaxfirst(t_stack *stack, int max);
void		ft_turk_sort(t_stack *a, t_stack *b, t_manager *manager);
void		ft_find_cheapest_moves(t_stack *a, t_stack *b, t_moves *mmoves);
int			ft_calculate_moves(t_stack *a, t_stack *b, int index,
				t_moves *moves);
int			ft_find_target_index(int num, t_stack *stack);
t_stack		*ft_set_first_extremes(t_stack *stack);
void		ft_initmoves(t_moves *moves);
void		ft_set_limits(int num, t_stack *stack);
void		ft_check_bench(t_moves *bench, char *result);
void		ft_print_bench_moves(t_moves *bench);
int			ft_put_in_bench(int algorithm, float disorder);
t_stack		*ft_fill_index_array(t_stack *stack);
void		ft_fill_indexed_num(int *src, t_indexed_num *inums, int size);
void		ft_sort(t_indexed_num *src, t_indexed_num *tmp, int size);
void		ft_merge(t_indexed_num *left, t_indexed_num *right,
				t_indexed_num *tmp, int size);
void		ft_copy_to_src(t_indexed_num *src, t_indexed_num *tmp, int size);
void		ft_print_array(t_indexed_num *array, int size);
void		ft_strjoin_array(t_manager *manager, char *input);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:54:31 by shierro           #+#    #+#             */
/*   Updated: 2026/02/10 16:49:51 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_stacks(t_stack *a, t_stack *b, t_moves *moves,
		t_moves *bench)
{
	while (a->size > 0)
	{
		ft_initmoves(moves);
		ft_find_cheapest_moves(a, b, moves);
		while (moves->rr-- > 0)
			ft_check_bench(bench, ft_rotate_both(a, b));
		while (moves->rrr-- > 0)
			ft_check_bench(bench, ft_rotate_reverse_both(a, b));
		while (moves->ra-- > 0)
			ft_check_bench(bench, ft_rotate(a));
		while (moves->rb-- > 0)
			ft_check_bench(bench, ft_rotate(b));
		while (moves->rra-- > 0)
			ft_check_bench(bench, ft_rotate_reverse(a));
		while (moves->rrb-- > 0)
			ft_check_bench(bench, ft_rotate_reverse(b));
		ft_check_bench(bench, ft_push(b, a));
	}
}

static void	ft_set_b_head(t_stack *b, t_moves *bench)
{
	int	head;

	head = ft_find_target_index(b->biggest, b);
	if (head <= b->size / 2)
	{
		while (head > 0)
		{
			ft_check_bench(bench, ft_rotate(b));
			head--;
		}
	}
	else
	{
		while (head < b->size)
		{
			ft_check_bench(bench, ft_rotate_reverse(b));
			head++;
		}
	}
}

void	ft_turk_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*moves;
	t_moves	*bench;

	bench = ft_calloc(sizeof(t_moves), 1);
	if (manager->bench)
		bench->bench = 1;
	moves = ft_calloc(1, sizeof(t_moves));
	if (!moves)
	{
		free(bench);
		ft_free_all(manager, a, b, 1);
	}
	if (a->nums[0] > a->nums[1])
		ft_check_bench(bench, ft_swap(a));
	ft_check_bench(bench, ft_push(b, a));
	ft_check_bench(bench, ft_push(b, a));
	ft_set_first_extremes(b);
	ft_move_stacks(a, b, moves, bench);
	ft_set_b_head(b, bench);
	while (b->size > 0)
		ft_check_bench(bench, ft_push(a, b));
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
	free(moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:29:41 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/10 20:30:28 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	result;
	int	result2;

	result = 0;
	result2 = 0;
	if (nb < 1)
		return (0);
	while (result2 < nb)
	{
		result2 = result * result;
		if (result2 >= nb)
			return (result);
		result++;
	}
	return (0);
}

static void	ft_push_chunk(t_stack *a, t_stack *b, int chunk, t_moves *bench)
{
	int	count;
	int	until;

	count = 0;
	until = ft_sqrt(a->size + b->size) + chunk;
	while (count < until - chunk && a->size != 0)
	{
		if (a->index[0] >= chunk && a->index[0] < until)
		{
			if (a->index[0] < ((until - chunk) / 2) + chunk)
			{
				ft_check_bench(bench, ft_rotate(b));
				ft_rotate_array(b->index, b->size);
			}
			ft_check_bench(bench, ft_push(b, a));
			ft_push_array(b->index, a->index, b->size, a->size + 1);
			count++;
			continue ;
		}
		ft_check_bench(bench, ft_rotate(a));
		ft_rotate_array(a->index, a->size);
	}
}

static void	ft_manager_range_sort(t_stack *b, t_moves *bench, int state)
{
	if (!state)
	{
		ft_check_bench(bench, ft_rotate(b));
		ft_rotate_array(b->index, b->size);
	}
	else if (state)
	{
		ft_check_bench(bench, ft_rotate_reverse(b));
		ft_rotate_reverse_array(b->index, b->size);
	}
}

static void	ft_range_sort_aux(t_stack *a, t_stack *b, t_moves *bench)
{
	int	chunk;
	int	sqrt;
	int	limit;
	int	state;

	chunk = 0;
	state = 0;
	sqrt = ft_sqrt(a->size);
	while (a->size)
	{
		ft_push_chunk(a, b, chunk, bench);
		chunk = chunk + sqrt;
	}
	limit = chunk - sqrt;
	while (b->size > 0)
	{
		if (b->index[0] == b->size - 1)
		{
			ft_check_bench(bench, ft_push(a, b));
			ft_push_array(a->index, b->index, a->size, b->size + 1);
			chunk--;
			if (chunk == limit)
			{
				limit = chunk - sqrt;
				state = 0;
			}
		}
		else
			ft_manager_range_sort(b, bench, state);
		if (state == 1 && b->index[0] < limit)
			state = 0;
		if (b->index[0] < limit)
			state = 1;
		if (chunk == limit)
			limit = chunk - sqrt;
	}
}

void	ft_range_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*bench;

	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	ft_fill_index_array(a);
	ft_range_sort_aux(a, b, bench);
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}

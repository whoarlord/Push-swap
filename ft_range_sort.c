/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:29:41 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/10 17:28:09 by iarrien-         ###   ########.fr       */
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
			ft_check_bench(bench, ft_push(b, a));
			ft_push_array(b->index, a->index, b->size, a->size + 1);
			count++;
			continue ;
		}
		ft_check_bench(bench, ft_rotate(a));
		ft_rotate_array(a->index, a->size);
	}
}

static int	ft_manager_range_sort(t_stack *a, t_stack *b,
	t_moves *bench, int state)
{
	int result;

	result = 0;
	if (b->index[0] > b->index[1])
	{
		ft_check_bench(bench, ft_swap(b));
		ft_swap_array(b->index, b->size);
	}
	if (b->index[0] == b->size)
	{
		ft_check_bench(bench, ft_push(a, b));
		ft_push_array(a->index, b->index, a->size, b->size + 1);
		result--;
	}
	else if (!state)
	{
		ft_check_bench(bench, ft_rotate(b));
		ft_rotate_array(b->index, b->size);
	}
	else if (state)
	{
		ft_check_bench(bench, ft_rotate_reverse(b));
		ft_rotate_reverse_array(b->index, b->size);
	}
	return (result);
}

static void	ft_range_sort_aux(t_stack *a, t_stack *b, t_moves *bench)
{
	int	chunk;
	int	sqrt;
	int limit;
	int state;

	chunk = 1;
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
		if (b->index[0] == b->size)
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
			chunk = chunk - ft_manager_range_sort(a, b, bench, state);
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
	int		i;
	int		j;
	int		count;
	t_moves	*bench;

	i = 0;
	j = 0;
	count = 1;
	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	ft_fill_index(a, i, j, count);
	ft_range_sort_aux(a, b, bench);
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}

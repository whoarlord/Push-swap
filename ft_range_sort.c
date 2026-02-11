/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:29:41 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 13:54:12 by shierro          ###   ########.fr       */
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
			if (b->index[0] < ((until - chunk) / 2) + chunk && b->size > 1)
			{
				ft_check_bench(bench, ft_rotate(b));
				ft_rotate_array(b->index, b->size);
			}
			count++;
			continue ;
		}
		ft_check_bench(bench, ft_rotate(a));
		ft_rotate_array(a->index, a->size);
	}
}

static int	ft_find_max_sqrt(t_stack *stack, int sqrt)
{
	int	i;

	i = 0;
	while (i < sqrt)
	{
		if (stack->index[i] == stack->size - 1)
			return (i);
		i++;
	}
	i = stack->size - 1 - sqrt;
	while (i < stack->size)
	{
		if (stack->index[i] == stack->size - 1)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_push_max(t_stack *a, t_stack *b, t_moves *bench, int sqrt)
{
	int	i;

	i = 0;
	i = ft_find_max_sqrt(b, sqrt);
	if (i <= sqrt)
	{
		while (i > 0)
		{
			ft_check_bench(bench, ft_rotate(b));
			ft_rotate_array(b->index, b->size);
			i--;
		}
	}
	else
	{
		while (i < b->size)
		{
			ft_check_bench(bench, ft_rotate_reverse(b));
			ft_rotate_reverse_array(b->index, b->size);
			i++;
		}
	}
	ft_check_bench(bench, ft_push(a, b));
	ft_push_array(a->index, b->index, a->size, b->size + 1);
}

void	ft_range_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*bench;
	int		chunk;
	int		sqrt;
	int		i;

	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	ft_fill_index_array(a);
	chunk = 0;
	sqrt = ft_sqrt(a->size);
	while (a->size)
	{
		ft_push_chunk(a, b, chunk, bench);
		chunk = chunk + sqrt;
	}
	while (b->size > 0)
		ft_push_max(a, b, bench, sqrt);
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}

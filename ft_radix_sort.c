/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:06:14 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/13 12:59:25 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_digits(int *array, t_stack *a, int bit)
{
	int	i;
	int	zeros;

	i = 0;
	zeros = 0;
	while (i < a->size)
	{
		if (a->index[i] & (1 << bit))
			array[i] = 1;
		else
		{
			array[i] = 0;
			zeros++;
		}
		i++;
	}
	if (zeros == 0 || zeros == a->size)
		array[0] = -1;
}

static void	*ft_radix_sort_to(t_stack *origin, t_stack *dest, int *bit,
		t_moves *bench)
{
	int	i;
	int	size_before;
	int	*array;

	size_before = origin->size;
	array = ft_calloc(origin->size, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	ft_fill_digits(array, origin, *bit);
	if (array[0] == -1)
	{
		*bit = *bit + 1;
		return (origin);
	}
	while (origin->size > 0)
	{
		array[i] = ft_manage_array(&array[i], dest, origin, bench);
		i++;
		if (i >= size_before)
			break ;
	}
	*bit = *bit + 1;
	free(array);
	return (origin);
}

static void	ft_push_all(t_stack *origin, t_stack *dest, t_moves *bench)
{
	int	i;

	i = 0;
	while (origin->size > 0)
	{
		ft_check_bench(bench, ft_push(dest, origin));
		ft_push_array(dest->index, origin->index, dest->size, origin->size + 1);
		i++;
	}
}

int	ft_calculate_bits(int size)
{
	int	result;

	result = 1;
	while (size > 1)
	{
		size = size / 2;
		result++;
	}
	return (result);
}

void	ft_radix_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	int		bit;
	t_moves	*bench;
	int		count;
	int		i;

	bit = 0;
	i = 0;
	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	if (!ft_fill_index_array(a))
		return (free(bench), ft_free_all(manager, a, b, 1));
	count = ft_calculate_bits(a->size);
	while (i < count)
	{
		if (!ft_radix_sort_to(a, b, &bit, bench))
			return (free(bench), ft_free_all(manager, a, b, 1));
		ft_push_all(b, a, bench);
		i++;
	}
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}

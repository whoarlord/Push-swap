/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:18:14 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/16 13:52:44 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_until_min(t_stack *a, t_moves *bench,
	int min, int minindex)
{
	while (a->nums[0] != min)
	{
		if (minindex < a->size / 2)
			ft_check_bench(bench, ft_rotate(a));
		else
			ft_check_bench(bench, ft_rotate_reverse(a));
	}
}

static void	ft_selection_sort_aux(t_stack *a, t_stack *b, t_moves *bench)
{
	int	min;
	int	i;
	int	minindex;

	while (a->size > 0)
	{
		i = 1;
		min = a->nums[0];
		while (i < a->size)
		{
			if (a->nums[i] < min)
			{
				min = a->nums[i];
				minindex = i;
			}
			i++;
		}
		ft_rotate_until_min(a, bench, min, minindex);
		ft_check_bench(bench, ft_push(b, a));
	}
	while (b->size > 0)
		ft_check_bench(bench, ft_push(a, b));
}

void	ft_selection_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*bench;

	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	ft_selection_sort_aux(a, b, bench);
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}


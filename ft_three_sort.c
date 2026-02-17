/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:26:44 by shierro           #+#    #+#             */
/*   Updated: 2026/02/17 11:38:30 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_numbers_bigger_first(t_moves *bench, t_stack *a)
{
	if (a->nums[1] > a->nums[2])
	{
		ft_check_bench(bench, ft_swap(a));
		ft_check_bench(bench, ft_rotate_reverse(a));
	}
	else
	{
		if (a->nums[0] > a->nums[2])
			ft_check_bench(bench, ft_rotate(a));
		else
			ft_check_bench(bench, ft_swap(a));
	}
}

void	ft_sort_three_numbers(t_manager *manager, t_stack *a, t_stack *b)
{
	t_moves	*bench;

	bench = ft_calloc(sizeof(t_moves), 1);
	if (!bench)
		ft_free_all(manager, a, b, 1);
	if (manager->bench)
		bench->bench = 1;
	if (a->nums[0] < a->nums[1])
	{
		ft_check_bench(bench, ft_rotate_reverse(a));
		if (compute_disorder(a))
			ft_check_bench(bench, ft_swap(a));
	}
	else
		ft_three_numbers_bigger_first(bench, a);
	if (bench->bench)
		ft_print_bench_moves(bench);
	free(bench);
}

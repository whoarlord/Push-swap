/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:54:31 by shierro           #+#    #+#             */
/*   Updated: 2026/02/09 17:13:01 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_stacks(t_stack *a, t_stack *b, t_moves *moves)
{
	while (a->size > 0)
	{
		ft_initmoves(moves);
		ft_find_cheapest_moves(a, b, moves);
		while (moves->rr-- > 0)
			ft_printf("%s\n", ft_rotate_both(a, b));
		while (moves->rrr-- > 0)
			ft_printf("%s\n", ft_rotate_reverse_both(a, b));
		while (moves->ra-- > 0)
			ft_printf("%s\n", ft_rotate(a));
		while (moves->rb-- > 0)
			ft_printf("%s\n", ft_rotate(b));
		while (moves->rra-- > 0)
			ft_printf("%s\n", ft_rotate_reverse(a));
		while (moves->rrb-- > 0)
			ft_printf("%s\n", ft_rotate_reverse(b));
		ft_printf("%s\n", ft_push(b, a));
	}
}

static void	ft_set_b_head(t_stack *b)
{
	int	head;

	head = ft_find_target_index(b->biggest, b);
	if (head <= b->size / 2)
	{
		while (head > 0)
		{
			ft_printf("%s\n", ft_rotate(b));
			head--;
		}
	}
	else
	{
		while (head < b->size)
		{
			ft_printf("%s\n", ft_rotate_reverse(b));
			head++;
		}
	}
}

void	ft_turk_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*moves;

	moves = ft_calloc(1, sizeof(t_moves));
	if (!moves)
		ft_free_all(manager, a, b, 1);
	if (a->nums[0] > a->nums[1])
		ft_printf("%s\n", ft_swap(a));
	ft_printf("%s\n", ft_push(b, a));
	ft_printf("%s\n", ft_push(b, a));
	ft_set_first_extremes(b);
	ft_move_stacks(a, b, moves);
	ft_set_b_head(b);
	while (b->size > 0)
		ft_printf("%s\n", ft_push(a, b));
	free(moves);
}

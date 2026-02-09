/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:45:04 by shierro           #+#    #+#             */
/*   Updated: 2026/02/09 14:11:44 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_set_first_extremes(t_stack *stack)
{
	if (stack->nums[0] > stack->nums[1])
	{
		stack->biggest = stack->nums[0];
		stack->smallest = stack->nums[1];
	}
	else
	{
		stack->smallest = stack->nums[0];
		stack->biggest = stack->nums[1];
	}
	return (stack);
}

void	ft_set_limits(int num, t_stack *stack)
{
	int	i;

	i = 0;
	if (num > stack->biggest || num < stack->smallest)
	{
		while (i < stack->size)
		{
			if (stack->nums[i] == stack->biggest)
			{
				if (num > stack->biggest)
					stack->biggest = num;
				else
					stack->smallest = num;
			}
			i++;
		}
	}
}

int	ft_find_target_index(int num, t_stack *stack)
{
	int	i;

	i = 0;
	if (num >= stack->biggest || num <= stack->smallest)
	{
		while (i < stack->size)
		{
			if (stack->nums[i] == stack->biggest)
				return (i);
			i++;
		}
	}
	else
	{
		if (stack->nums[stack->size - 1] > num && stack->nums[0] < num)
			return (0);
		while (i < stack->size - 1)
		{
			if (stack->nums[i] > num && stack->nums[i + 1] < num)
				return (i + 1);
			i++;
		}
	}
	return (i);
}

int	ft_calculate_moves(t_stack *a, t_stack *b, int index, t_moves *moves)
{
	int	target;

	if (index <= a->size / 2)
		moves->ra = index;
	else
		moves->rra = a->size - index;
	target = ft_find_target_index(a->nums[index], b);
	if (target <= b->size / 2)
		moves->rb = target;
	else
		moves->rrb = b->size - target;
	while (moves->ra > 0 && moves->rb > 0)
	{
		moves->rr++;
		moves->ra--;
		moves->rb--;
	}
	while (moves->rra > 0 && moves->rrb > 0)
	{
		moves->rrr++;
		moves->rra--;
		moves->rrb--;
	}
	return (moves->ra + moves->rb + moves->rr + moves->rra + moves->rrb
		+ moves->rrr + moves->sa + moves->sb + 1);
}

void	ft_find_cheapest_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	int	i;
	int	cheapest_moves;
	int	j;
	int	movs;

	i = 1;
	j = 0;
	cheapest_moves = ft_calculate_moves(a, b, 0, moves);
	ft_initmoves(moves);
	while (i < a->size)
	{
		movs = ft_calculate_moves(a, b, i, moves);
		if (movs < cheapest_moves)
		{
			cheapest_moves = movs;
			j = i;
		}
		ft_initmoves(moves);
		i++;
	}
	ft_calculate_moves(a, b, j, moves);
	ft_set_limits(a->nums[j], b);
}

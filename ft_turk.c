/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:54:31 by shierro           #+#    #+#             */
/*   Updated: 2026/02/06 18:15:02 by shierro          ###   ########.fr       */
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

int	ft_find_target_index(int num, t_stack *stack)
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
				return (i);
			}
			i++;
		}
	}
	else
	{
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
		moves->rra = a->size - index + 1;
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
			ft_printf("CHEAPEST MOVES INTERNO: %i\n", movs);
			j = i;
		}
		ft_initmoves(moves);
		i++;
	}
	// ft_printf("ANTES\n");
	// ft_printmoves(moves);
	ft_calculate_moves(a, b, j, moves);
	// ft_printf("DESPUES\n");
	// ft_printmoves(moves);
}

void	ft_turk(t_stack *a, t_stack *b, t_manager *manager)
{
	t_moves	*moves;
	int		head;

	moves = malloc(sizeof(t_borders));
	if (!moves)
	{
		ft_free_all(manager, a, b);
		write(2, "Error\n", 6);
		exit(1);
	}
	ft_printf("%s\n", ft_push(b, a));
	ft_printf("%s\n", ft_push(b, a));
	ft_set_first_extremes(b);
	while (a->size > 0)
	{
		ft_initmoves(moves);
		ft_find_cheapest_moves(a, b, moves);
		// ft_printmoves(moves);
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
		while (head <= b->size)
		{
			ft_printf("%s\n", ft_rotate_reverse(b));
			head++;
		}
	}
	while (b->size > 0)
		ft_printf("%s\n", ft_push(a, b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:30:37 by shierro           #+#    #+#             */
/*   Updated: 2026/02/06 12:38:21 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_bubble_sort(t_stack *a)
// {
// 	int	*nums;

// 	nums = a->nums;
// 	while (compute_disorder(a) > 0)
// 	{
// 		if (nums[0] < nums[1])
// 		{
// 			ft_printf("%s\n", ft_swap(a));
// 		}
// 		if (compute_disorder(a) == 0)
// 			return ;
// 		if (compute_disorder(a) == 1)
// 		{
// 		}
// 		ft_printf("%s\n", ft_rotate(a));
// 	}
// }

// void	ft_selection_sort(t_stack *a, t_stack *b)
// {
// 	int	min;
// 	int	i;
// 	int	minindex;
// 	int	*nums;

// 	nums = a->nums;
// 	while (a->size > 0)
// 	{
// 		i = 1;
// 		min = nums[0];
// 		while (i < a->size)
// 		{
// 			if (nums[i] < min)
// 			{
// 				min = nums[i];
// 				minindex = i;
// 			}
// 			i++;
// 		}
// 		while (nums[0] != min)
// 		{
// 			if (minindex < a->size / 2)
// 				ft_printf("%s\n", ft_rotate(a));
// 			else
// 				ft_printf("%s\n", ft_rotate_reverse(a));
// 		}
// 		ft_printf("%s\n", ft_push(b, a));
// 	}
// 	while (b->size > 0)
// 		ft_printf("%s\n", ft_push(a, b));
// }

void	ft_push_borders(t_stack *a, t_stack *b, t_borders *borders)
{
	if (borders->minindex < borders->maxindex)
	{
		if (borders->minindex < a->size - 1 - borders->maxindex)
			ft_min_closer_to_start(a, b, borders);
		else
			ft_max_closer_to_end(a, b, borders);
	}
	else
	{
		if (borders->maxindex < a->size - 1 - borders->minindex)
			ft_max_closer_to_start(a, b, borders);
		else
			ft_min_closer_to_end(a, b, borders);
	}
}

void	ft_adjust_b_position(int n, t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->size - 1)
	{
		if (n < b->nums[i] && n > b->nums[i + 1])
			break ;
		i++;
	}
	if (i < b->size / 2)
		ft_printf("%s\n", ft_rotate(b));
	else
		ft_printf("%s\n", ft_rotate_reverse(b));
}

void	ft_putmaxfirst(t_stack *stack, int max)
{
	int	i;

	i = 0;
	while (stack->nums[i] < stack->size)
	{
		if (stack->nums[i] == max)
			break ;
		i++;
	}
	if (i < stack->size / 2)
		ft_printf("%s\n", ft_rotate(stack));
	else
		ft_printf("%s\n", ft_rotate_reverse(stack));
}

void	ft_interpolation_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	t_borders	*borders;

	borders = malloc(sizeof(t_borders));
	if (!borders)
	{
		ft_free_all(manager, a, b);
		write(2, "Error\n", 6);
		exit(1);
	}
	borders = ft_get_borders(a, borders);
	ft_push_borders(a, b, borders);
	while (a->size > 0)
	{
		if (a->nums[0] > b->nums[0] && a->nums[0] < b->nums[b->size - 1])
			ft_printf("%s\n", ft_push(b, a));
		else
			ft_adjust_b_position(a->nums[0], b);
	}
	ft_putmaxfirst(b, borders->max);
	while (b->size > 0)
		ft_printf("%s\n", ft_push(a, b));
}

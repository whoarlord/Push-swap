/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:30:37 by shierro           #+#    #+#             */
/*   Updated: 2026/02/10 16:19:01 by shierro          ###   ########.fr       */
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

void	ft_selection_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	i;
	int	minindex;
	int	*nums;

	nums = a->nums;
	while (a->size > 0)
	{
		i = 1;
		min = nums[0];
		while (i < a->size)
		{
			if (nums[i] < min)
			{
				min = nums[i];
				minindex = i;
			}
			i++;
		}
		while (nums[0] != min)
		{
			if (minindex < a->size / 2)
				ft_printf("%s\n", ft_rotate(a));
			else
				ft_printf("%s\n", ft_rotate_reverse(a));
		}
		ft_printf("%s\n", ft_push(b, a));
	}
	while (b->size > 0)
		ft_printf("%s\n", ft_push(a, b));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:30:37 by shierro           #+#    #+#             */
/*   Updated: 2026/02/05 16:06:03 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stack *a)
{
	int	*nums;
	int i;
	int min;

	nums = a->nums;
	i = 1;
	min = nums[0];
	while (i < a->size)
	{
		if (nums[i] < min)
			min = nums[i];
		i++;
	}
	while (compute_disorder(a) > 0)
	{
		if (nums[0] > nums[1] && min != nums[0] && min != nums[1])
		{
			ft_printf("%s\n", ft_swap(a));
		}
		if (compute_disorder(a) == 0)
			return ;
		ft_printf("%s\n", ft_rotate(a));
	}
}

void	ft_selection_sort(t_stack *a, t_stack *b)
{
	int	min;
	int	i;
	int	*nums;

	nums = a->nums;
	while (a->size > 0)
	{
		i = 1;
		min = nums[0];
		while (i < a->size)
		{
			if (nums[i] < min)
				min = nums[i];
			i++;
		}
		while (nums[0] != min)
		{
			ft_printf("%s\n", ft_rotate(a));
		}
		ft_printf(ft_push(b, a));
	}
	while (b->size > 0)
		ft_printf(ft_push(a, b));
}

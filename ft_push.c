/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:20:51 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/06 10:58:43 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if direction is 0, move from top to bottom, if direction is 1 do it reverse
static void	ft_offset(t_stack *stack, int direction)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size - 1)
	{
		if (direction)
		{
			temp = stack->nums[i];
			stack->nums[i] = stack->nums[i + 1];
			stack->nums[i + 1] = temp;
			i++;
			continue ;
		}
		temp = stack->nums[stack->size - 1 - i];
		stack->nums[stack->size - 1 - i] = stack->nums[stack->size - 2 - i];
		stack->nums[stack->size - 2 - i] = temp;
		i++;
	}
}

char	*ft_push(t_stack *dest, t_stack *src)
{
	if (src->size == 0)
	{
		if (dest->type == 'a')
			return ("pa");
		return ("pb");
	}
	dest->size++;
	ft_offset(dest, 0);
	dest->nums[0] = src->nums[0];
	ft_offset(src, 1);
	src->size--;
	if (dest->type == 'a')
		return ("pa");
	return ("pb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:20:51 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 20:03:59 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if direction is 0, move from top to bottom, if direction is 1 do it reverse
void	ft_offset(t_stack *stack, int direction)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size)
	{
		temp = stack->nums[stack->size - i];
		stack->nums[stack->size - i] = stack->nums[stack->size - i - 1];
		stack->nums[stack->size - i - 1] = temp;
	}
	if (direction)
	{

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
}

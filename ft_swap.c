/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:10:28 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 16:18:08 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_swap(t_stack *stack)
{
	int	temp;

	temp = 0;
	if (stack->size <= 1)
		return ("");
	temp = stack->nums[0];
	stack->nums[0] = stack->nums[1];
	stack->nums[1] = temp;
	if (stack->type == 'a')
		return ("sa");
	return ("sb");
}

char	*ft_swap_both(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	return ("ss");
}

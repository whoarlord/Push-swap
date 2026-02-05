/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:21:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/05 13:25:20 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate_reverse(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size - 1)
	{
		temp = stack->nums[stack->size - 1 - i];
		stack->nums[stack->size - 1 - i] = stack->nums[stack->size - 2 - i];
		stack->nums[stack->size - 2 - i] = temp;
		i++;
	}
	if (stack->type == 'a')
		return ("rra");
	return ("rrb");
}

char	*ft_rotate_reverse_both(t_stack *a, t_stack *b)
{
	ft_rotate_reverse(a);
	ft_rotate_reverse(b);
	return ("rrr");
}

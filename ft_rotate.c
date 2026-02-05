/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:01:58 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/05 13:12:26 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stack->size - 1)
	{
		temp = stack->nums[i];
		stack->nums[i] = stack->nums[i + 1];
		stack->nums[i + 1] = temp;
		i++;
	}
	if (stack->type == 'a')
		return ("ra");
	return ("rb");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:05 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 11:44:58 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_manager(t_manager *manager)
{
	if (manager->numbers)
		ft_free_split(manager->numbers);
	free(manager);
}

void	ft_free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->nums)
		free(stack->nums);
	if (stack->index)
		free(stack->index);
	free(stack);
}

void	ft_free_all(t_manager *manager, t_stack *a, t_stack *b)
{
	ft_free_manager(manager);
	ft_free_stack(a);
	ft_free_stack(b);
}

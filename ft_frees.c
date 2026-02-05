/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:05 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/05 11:30:52 by shierro          ###   ########.fr       */
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
	free(stack);
}

void	ft_free_all(t_manager *manager, t_stack *a, t_stack *b)
{
	ft_free_manager(manager);
	ft_free_stack(a);
	ft_free_stack(b);
}

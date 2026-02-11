/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:59:09 by shierro           #+#    #+#             */
/*   Updated: 2026/02/11 13:59:24 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_manage_array(int *array, t_stack *dest, t_stack *origin, t_moves *bench)
{
	if (*array == 0)
	{
		ft_check_bench(bench, ft_push(dest, origin));
		ft_push_array(dest->index, origin->index, dest->size, origin->size + 1);
		return (-1);
	}
	else if (*array != -1)
	{
		ft_check_bench(bench, ft_rotate(origin));
		ft_rotate_array(origin->index, origin->size);
	}
	return (*array);
}

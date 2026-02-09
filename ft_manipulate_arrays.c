/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:29:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 13:02:03 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_array(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		temp = array[i];
		array[i] = array[i + 1];
		array[i + 1] = temp;
		i++;
	}
}

static void	ft_offset_array(int *array, int size, int direction)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (direction)
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i++;
			continue ;
		}
		temp = array[size - 1 - i];
		array[size - 1 - i] = array[size - 2 - i];
		array[size - 2 - i] = temp;
		i++;
	}
}

void	ft_push_array(int *dest, int *src, int size_dest, int size_src)
{
	ft_offset_array(dest, size_dest, 0);
	dest[0] = src[0];
	ft_offset_array(src, size_src, 1);
}

int	ft_manage_array(int *array, t_stack *dest, t_stack *origin, t_moves *bench)
{
	if (*array == 0)
	{
		ft_check_bench(bench, ft_push(dest, origin));
		ft_push_array(dest->index, origin->index,
			dest->size, origin->size + 1);
		return (-1);
	}
	else if (*array != -1)
	{
		ft_check_bench(bench, ft_rotate(origin));
		ft_rotate_array(origin->index, origin->size);
	}
	return (*array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:29:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 13:59:26 by shierro          ###   ########.fr       */
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

void	ft_rotate_reverse_array(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size - 1)
	{
		temp = array[size - i - 1];
		array[size - i - 1] = array[size - i - 2];
		array[size - i - 2] = temp;
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

void	ft_swap_array(int *array, int size)
{
	int	temp;

	if (size <= 1)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
}

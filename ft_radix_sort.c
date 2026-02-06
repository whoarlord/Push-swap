/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:06:14 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/06 11:36:36 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_digits(int *array, t_stack *a, int bit)
{
	int	i;
	int	equal;

	i = 0;
	equal = 0;
	while (i < a->size)
	{
		if (a->nums[i] & (1 << bit))
		{
			array[i] = 1;
			equal++;
		}
		else
			array[i] = 0;
		i++;
	}
	if (equal == 0 || equal == a->size)
		array[0] = -1;
}

static void	ft_push_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		ft_printf("%s\n", ft_push(a, b));
	}
}

void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	*array;
	int	bit;
	int	i;
	int	size_before;
	int	type;

	array = ft_calloc(a->size, sizeof(int));
	bit = 0;
	size_before = a->size;
	while (compute_disorder(a))
	{
		i = 0;
		ft_fill_digits(array, a, bit);
		if (array[0] == -1)
		{
			bit++;
			if (bit == 32)
				break ;
			continue ;
		}
		type = 0;
		while (a->size > 0)
		{
			if (array[i] == type)
			{
				ft_printf("%s\n", ft_push(b, a));
				array[i] = -1;
			}
			else
				ft_printf("%s\n", ft_rotate(a));
			i++;
			if (i >= size_before)
			{
				type = 1;
				i = 0;
			}
		}
		ft_push_to_a(a, b);
		bit++;
		if (bit == 32)
			break ;
	}
}

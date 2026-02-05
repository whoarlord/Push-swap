/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:06:14 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/05 17:20:01 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_biggest_number(int *array, int n, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size + 1)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	if (n == max)
		return (1);
	return (0);
}

static void	ft_fill_digits(int *array, t_stack *a, int bit)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->nums[i] & (1 << bit))
			array[i] = 1;
		else
			array[i] = 1;
		i++;
	}
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
	int	power;
	int	i;
	int	size_before;

	array = ft_calloc(a->size, sizeof(int));
	power = 0;
	size_before = a->size - 1;
	i = size_before;
	while (compute_disorder(a))
	{
		ft_fill_digits(array, a, power);
		while (a->size > 0)
		{
			ft_printf("%s\n", ft_rotate_reverse(a));
			if (ft_biggest_number(array, array[i], size_before))
			{
				ft_printf("%s\n", ft_push(b, a));
				array[i] = -1;
			}
			i--;
			if (i < 0)
				i = size_before;
		}
		ft_push_to_a(a, b);
		power++;
	}
}

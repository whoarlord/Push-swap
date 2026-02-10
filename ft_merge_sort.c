/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:22:14 by shierro           #+#    #+#             */
/*   Updated: 2026/02/10 16:23:39 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_print_array(t_indexed_num *array, int size)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("[");
// 	while (i < size - 1)
// 	{
// 		ft_printf("%i, ", array[i++].num);
// 	}
// 	ft_printf("%i]\n", array[i++].num);
// 	i = 0;
// 	ft_printf("[");
// 	while (i < size - 1)
// 	{
// 		ft_printf("%i, ", array[i++].index);
// 	}
// 	ft_printf("%i]\n", array[i++].index);
// }

void	ft_copy_to_src(t_indexed_num *src, t_indexed_num *tmp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		src[i] = tmp[i];
		i++;
	}
}

void	ft_merge(t_indexed_num *left, t_indexed_num *right, t_indexed_num *tmp,
		int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		if (j == size / 2)
			tmp[i++] = right[k++];
		else if (k == size - size / 2)
			tmp[i++] = left[j++];
		else if (left[j].num <= right[k].num)
			tmp[i++] = left[j++];
		else
			tmp[i++] = right[k++];
	}
	ft_copy_to_src(left, tmp, size);
}

void	ft_sort(t_indexed_num *src, t_indexed_num *tmp, int size)
{
	int	half;

	half = size / 2;
	if (size == 1)
		return ;
	ft_sort(src, tmp, half);
	ft_sort(src + half, tmp, size - half);
	ft_merge(src, src + half, tmp, size);
}

void	ft_fill_indexed_num(int *src, t_indexed_num *inums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		inums[i].num = src[i];
		inums[i].index = i;
		i++;
	}
}

t_stack	*ft_fill_index_array(t_stack *stack)
{
	t_indexed_num	*tmp;
	t_indexed_num	*inums;
	int				i;

	i = 0;
	inums = malloc(stack->size * sizeof(t_indexed_num));
	if (!inums)
		return (NULL);
	tmp = malloc(stack->size * sizeof(t_indexed_num));
	if (!tmp)
		return (free(inums), NULL);
	ft_fill_indexed_num(stack->nums, inums, stack->size);
	// ft_print_array(inums, stack->size);
	ft_sort(inums, tmp, stack->size);
	// ft_print_array(inums, stack->size);
	while (i < stack->size)
	{
		stack->index[inums[i].index] = i;
		i++;
	}
	free(inums);
	free(tmp);
	return (stack);
}

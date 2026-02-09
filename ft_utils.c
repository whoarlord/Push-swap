/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:47 by shierro           #+#    #+#             */
/*   Updated: 2026/02/06 17:13:44 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	float	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs += 1;
			if (a->nums[i] > a->nums[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	result = mistakes / total_pairs;
	// printf("DISORDER = %f\n", result);
	// ft_print_stack(a);
	return (result);
}

float	compute_disorder_reverse(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	float	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs += 1;
			if (a->nums[i] < a->nums[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	result = mistakes / total_pairs;
	// printf("DISORDER = %f\n", result);
	// ft_print_stack(a);
	return (result);
}

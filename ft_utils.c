/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:47 by shierro           #+#    #+#             */
/*   Updated: 2026/02/05 12:37:39 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
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
	return (mistakes / total_pairs);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:31:47 by shierro           #+#    #+#             */
/*   Updated: 2026/02/11 14:00:48 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	ft_printmoves(t_moves *moves)
// {
// 	ft_printf("MOVES\n");
// 	ft_printf("ra: %i\nrb: %i\nrr: %i\nrra: %i\nrrb: %i\nrrr: %i\n", moves->ra,
// 		moves->rb, moves->rr, moves->rra, moves->rrb, moves->rrr);
// }

void	ft_initmoves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->sa = 0;
	moves->sb = 0;
}

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
	return (result);
}

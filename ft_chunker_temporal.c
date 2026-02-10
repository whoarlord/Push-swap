/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunker_temporal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:15:47 by shierro           #+#    #+#             */
/*   Updated: 2026/02/10 17:59:45 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_chunks(t_stack *a)
{
	int	i;

	i = 0;
	while (i * i < a->size)
		i++;
	return (i);
}

int	ft_get_chunk_size(t_stack *a)
{
	int	i;

	i = 0;
	while (i * i < a->size)
		i++;
	if (i * i == a->size)
		return (i);
	else
		return (i - 1);
}

void	ft_order_with_chunks(t_stack *a, t_stack *b, t_chunk *chunks,
		t_moves *bench)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_get_chunks(a))
	{
		j = 0;
		while (chunks[i].size > 0 && j < a->size)
		{
			if (a->index[j] >= chunks[i].min && a->index[j] <= chunks[i].max)
			{
				ft_check_bench(bench, ft_push(b, a));
				chunks[i].size--;
			}
			j++;
		}
		i++;
	}
}

void	ft_chunk_sort(t_stack *a, t_stack *b, t_manager *manager)
{
	int		chunk_size;
	t_chunk	*chunks;
	t_moves	*bench;
	int		i;
	int		j;

	j = 0;
	i = 0;
	chunk_size = ft_get_chunk_size(a);
	chunks = malloc(ft_get_chunks(a) * sizeof(t_chunk));
	if (!chunks)
		ft_free_all(manager, a, b, 1);
	bench = malloc(sizeof(t_moves));
	while (i < ft_get_chunks(a))
	{
		chunks[i].min = j;
		chunks[i].max = j + chunk_size - 1;
		chunks[i].size = chunk_size;
		if (j + chunk_size >= a->size)
			chunks[i].size = a->size - i;
		j = j + chunk_size;
		i++;
	}
	ft_print_stack(a);
	ft_order_with_chunks(a, b, chunks, bench);
	ft_print_stack(b);
	free(bench);
	free(chunks);
}

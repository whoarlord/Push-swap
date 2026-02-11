/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:29:57 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 16:49:19 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_do_moves(t_stack *a, t_stack *b, char *moves)
{
	if (!ft_strncmp(moves, "pa\n", 3))
		return (ft_push(a, b), 3);
	else if (!ft_strncmp(moves, "pb\n", 3))
		return (ft_push(b, a), 3);
	else if (!ft_strncmp(moves, "sa\n", 3))
		return (ft_swap(a), 3);
	else if (!ft_strncmp(moves, "sb\n", 3))
		return (ft_swap(b), 3);
	else if (!ft_strncmp(moves, "ss\n", 3))
		return (ft_swap_both(a, b), 3);
	else if (!ft_strncmp(moves, "rra\n", 4))
		return (ft_rotate_reverse(a), 4);
	else if (!ft_strncmp(moves, "rrb\n", 4))
		return (ft_rotate_reverse(b), 4);
	else if (!ft_strncmp(moves, "rrr\n", 4))
		return (ft_rotate_both(a, b), 4);
	else if (!ft_strncmp(moves, "ra\n", 3))
		return (ft_rotate(a), 3);
	else if (!ft_strncmp(moves, "rb\n", 3))
		return (ft_rotate(b), 3);
	else if (!ft_strncmp(moves, "rr\n", 3))
		return (ft_rotate_both(a, b), 3);
	else
		return (0);
}

int	ft_loop_moves(t_stack *a, t_stack *b, char *moves)
{
	int	chars_count;

	chars_count = 0;
	while (*moves)
	{
		chars_count = ft_do_moves(a, b, moves);
		if (chars_count == 0)
			return (1);
		moves = moves + chars_count;
	}
	return (0);
}

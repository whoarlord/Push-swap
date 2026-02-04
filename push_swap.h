/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:26:15 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 15:38:06 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/ft_printf.h"

typedef struct s_manager
{
	int		algorithm;
	int		bench;
	int		error;
	char	**numbers;
}			t_manager;

typedef struct s_stack
{
	int		*nums;
	int		size;
	char	type;
}			t_stack;
#endif
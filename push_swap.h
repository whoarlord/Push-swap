/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:26:15 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/05 11:26:32 by shierro          ###   ########.fr       */
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

void		*ft_init_stacks(int size, char **numstr, t_stack *a, t_stack *b);
t_manager	*ft_fill_manager(int argc, char *argv[]);
void		ft_free_manager(t_manager *manager);
void		ft_free_stack(t_stack *stack);
void		ft_free_all(t_manager *manager, t_stack *a, t_stack *b);
int			ft_validate_numinput(char **numstr);
int			ft_check_doubles(int *nums, int size);
#endif

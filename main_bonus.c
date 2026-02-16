/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:57:42 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/16 16:02:34 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_check_allocs(t_manager *manager, t_stack **a, t_stack **b,
		int size)
{
	if (size == 0)
		ft_free_all(manager, *a, *b, 1);
	*a = ft_calloc(1, sizeof(t_stack));
	if (!*a)
		ft_free_all(manager, *a, *b, 1);
	*b = ft_calloc(1, sizeof(t_stack));
	if (!*b)
		ft_free_all(manager, *a, *b, 1);
	*a = ft_init_stacks(size, manager->numbers, *a, *b);
	if (!*a)
		ft_free_all(manager, *a, *b, 1);
	if (ft_check_doubles((*a)->nums, (*a)->size))
		ft_free_all(manager, *a, *b, 1);
}

static char	*ft_check_input(void)
{
	char	*result;
	char	*temp;

	temp = ft_calloc(1, 1);
	if (!temp)
		return (NULL);
	result = ft_calloc(1, 1);
	if (!result)
		return (free(temp), NULL);
	while (temp)
	{
		free(temp);
		temp = get_next_line(0);
		if (!temp)
			break ;
		result = ft_strjoin_line(result, temp);
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	t_manager	*manager;
	t_stack		*a;
	t_stack		*b;
	int			size;
	char		*moves;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (1);
	manager = ft_fill_manager(argc, argv);
	size = ft_validate_numinput(manager->numbers);
	ft_check_allocs(manager, &a, &b, size);
	moves = ft_check_input();
	if (!moves)
		return (ft_free_all(manager, a, b, 1), 1);
	ft_printf("%s\n", moves);
	if (ft_loop_moves(a, b, moves))
		return (free(moves), ft_free_all(manager, a, b, 1), 1);
	if (b->size == 0 && compute_disorder(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free(moves), ft_free_all(manager, a, b, 0), 0);
}

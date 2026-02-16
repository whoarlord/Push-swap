/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/16 15:32:41 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_allocs(t_manager *manager, t_stack **a, t_stack **b,
		int size)
{
	char	*init;

	if (size == 0)
		ft_free_all(manager, *a, *b, 1);
	*a = ft_calloc(1, sizeof(t_stack));
	if (!*a)
		ft_free_all(manager, *a, *b, 1);
	*b = ft_calloc(1, sizeof(t_stack));
	if (!*b)
		ft_free_all(manager, *a, *b, 1);
	init = ft_init_stacks(size, manager->numbers, *a, *b);
	if (!init)
		ft_free_all(manager, *a, *b, 1);
	if (ft_check_doubles((*a)->nums, (*a)->size))
		ft_free_all(manager, *a, *b, 1);
}

static void	ft_manage_algorithm(t_stack *a, t_stack *b,
	t_manager *manager, float disorder)
{
	if (manager->algorithm == 0 || (manager->algorithm == 3 && disorder < 0.2))
		ft_selection_sort(a, b, manager);
	else if (manager->algorithm == 1 || (manager->algorithm == 3
			&& disorder < 0.5 && disorder >= 0.2))
		ft_range_sort(a, b, manager);
	else if (manager->algorithm == 2 || (manager->algorithm == 3
			&& disorder >= 0.5))
		ft_radix_sort(a, b, manager);
}

int	main(int argc, char *argv[])
{
	t_manager	*manager;
	t_stack		*a;
	t_stack		*b;
	int			size;
	float		disorder;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	manager = ft_fill_manager(argc, argv);
	size = ft_validate_numinput(manager->numbers);
	ft_check_allocs(manager, &a, &b, size);
	disorder = compute_disorder(a);
	if (manager->bench)
		if (ft_put_in_bench(manager->algorithm, disorder))
			ft_free_all(manager, a, b, 1);
	if (disorder == 0)
		return (ft_bench_fill_zeros(), ft_free_all(manager, a, b, 0), 0);
	ft_manage_algorithm(a, b, manager, disorder);
	ft_free_all(manager, a, b, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 14:12:16 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	// ft_printf("Stack type: %c\n", stack->type);
	// ft_printf("Size: %d\n", stack->size);
	while (i < stack->size)
		ft_printf("%d\n", stack->nums[i++]);
} */

static void	ft_check_allocs(t_manager *manager,
			t_stack **a, t_stack **b, int size)
{
	if (size == 0)
		ft_free_all(manager, *a, *b, 1);
	*a = malloc(sizeof(t_stack));
	if (!*a)
		ft_free_all(manager, *a, *b, 1);
	*b = malloc(sizeof(t_stack));
	if (!*b)
		ft_free_all(manager, *a, *b, 1);
	*a = ft_init_stacks(size, manager->numbers, *a, *b);
	if (!*a)
		ft_free_all(manager, *a, *b, 1);
	if (ft_check_doubles((*a)->nums, (*a)->size))
		ft_free_all(manager, *a, *b, 1);
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
	manager = ft_fill_manager(argc, argv);
	size = ft_validate_numinput(manager->numbers);
	ft_check_allocs(manager, &a, &b, size);
	disorder = compute_disorder(a);
	if (manager->bench)
		if (ft_put_in_bench(manager->algorithm, disorder))
			ft_free_all(manager, a, b, 1);
	if (manager->algorithm == 2 ||
		(manager->algorithm == 3 && disorder > 0.5))
		ft_radix_sort(a, b, manager);
	ft_free_all(manager, a, b, 0);
}

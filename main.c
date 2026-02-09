/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 13:19:12 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	// ft_printf("Stack type: %c\n", stack->type);
	// ft_printf("Size: %d\n", stack->size);
	while (i < stack->size)
		ft_printf("%d\n", stack->nums[i++]);
}

int	main(int argc, char *argv[])
{
	t_manager	*manager;
	t_stack		*a;
	t_stack		*b;
	int			size;
	float		disorder;

	manager = ft_fill_manager(argc, argv);
	size = ft_validate_numinput(manager->numbers);
	if (size == 0)
		return (write(2, "Error\n", 6), ft_free_manager(manager), 1);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (write(2, "Error\n", 6), ft_free_manager(manager), 1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (write(2, "Error\n", 6), ft_free_all(manager, a, b), 1);
	a = ft_init_stacks(size, manager->numbers, a, b);
	if (!a)
		return (write(2, "Error\n", 6), ft_free_all(manager, a, b), 1);
	if (ft_check_doubles(a->nums, a->size))
		return (write(2, "Error\n", 6), ft_free_all(manager, a, b), 1);
	disorder = compute_disorder(a);
	if (manager->bench)
		ft_put_in_bench(manager->algorithm, disorder);
	if (manager->algorithm == 2 ||
		(manager->algorithm == 3 && disorder > 0.5))
		ft_radix_sort(a, b);

}

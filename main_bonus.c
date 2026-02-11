/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:57:42 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 17:34:03 by iarrien-         ###   ########.fr       */
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
	result = ft_calloc(1, 1);
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

static t_manager	*ft_fill_manager_checker(int argc, char *argv[])
{
	int			i;
	t_manager	*manager;

	i = 1;
	manager = ft_calloc(1, sizeof(t_manager));
	if (!manager)
		exit(1);
	manager->algorithm = 3;
	while (i < argc || manager->error)
	{
		if (ft_strnstr(argv[i], "--", 2))
			manager->error = 1;
		else if (!manager->numbers)
		{
			manager->numbers = ft_split(argv[i], ' ');
			if (!manager->numbers)
				ft_free_all(manager, NULL, NULL, 1);
		}
		else
			ft_strjoin_array(manager, argv[i]);
		i++;
	}
	if (manager->error)
		ft_free_all(manager, NULL, NULL, 1);
	return (manager);
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
	manager = ft_fill_manager_checker(argc, argv);
	size = ft_validate_numinput(manager->numbers);
	ft_check_allocs(manager, &a, &b, size);
	moves = ft_check_input();
	ft_printf("%s\n", moves);
	if (ft_loop_moves(a, b, moves))
	{
		free(moves);
		ft_free_all(manager, a, b, 1);
	}
	if (b->size == 0 && compute_disorder(a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free(moves), ft_free_all(manager, a, b, 0), 0);
}

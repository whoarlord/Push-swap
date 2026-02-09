/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:50:23 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/09 12:32:42 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The algorithm
- number 0: simple
- number 1: medium
- number 2: complex
- number 3: adaptive
*/

void	*ft_init_stacks(int size, char **numstr, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	a->size = size;
	a->type = 'a';
	b->size = 0;
	b->type = 'b';
	a->nums = ft_calloc(size, sizeof(int));
	if (!a)
		return (NULL);
	b->nums = ft_calloc(size, sizeof(int));
	if (!b)
		return (ft_free_stack(a), NULL);
	while (numstr[i])
	{
		a->nums[i] = ft_atoi(numstr[i]);
		i++;
	}
	return (a);
}

static void	ft_which_flag(t_manager *manager, char *flag)
{
	if (ft_strnstr(flag, "--bench", 7))
		manager->bench = 1;
	else if (ft_strnstr(flag, "--simple", 8))
		manager->algorithm = 0;
	else if (ft_strnstr(flag, "--medium", 8))
		manager->algorithm = 1;
	else if (ft_strnstr(flag, "--complex", 9))
		manager->algorithm = 2;
	else if (ft_strnstr(flag, "--adaptive", 10))
		manager->algorithm = 3;
	else
		manager->error = 1;
}

static void	ft_fill_array(t_manager *manager, char **new_array)
{
	int	i;

	i = 0;
	while ((manager->numbers)[i])
	{
		new_array[i] = ft_strdup((manager->numbers)[i]);
		if (!new_array[i])
		{
			ft_free_split(new_array);
			manager->error = 1;
			return ;
		}
		i++;
	}
}

static void	ft_strjoin_array(t_manager *manager, char *input)
{
	int		size;
	char	**new_array;

	size = 0;
	while ((manager->numbers)[size])
		size++;
	new_array = malloc((size + 2) * sizeof(char *));
	if (!new_array)
	{
		manager->error = 1;
		return ;
	}
	ft_fill_array(manager, new_array);
	if (manager->error)
		return ;
	new_array[size] = ft_strdup(input);
	new_array[size + 1] = NULL;
	ft_free_split(manager->numbers);
	manager->numbers = new_array;
}

t_manager	*ft_fill_manager(int argc, char *argv[])
{
	int			i;
	t_manager	*manager;

	i = 1;
	manager = ft_calloc(1, sizeof(t_manager));
	manager->algorithm = 3;
	if (!manager)
		return (NULL);
	while (i < argc || manager->error)
	{
		if (ft_strnstr(argv[i], "--", 2))
			ft_which_flag(manager, argv[i]);
		else if (!manager->numbers)
			manager->numbers = ft_split(argv[i], ' ');
		else
			ft_strjoin_array(manager, argv[i]);
		i++;
	}
	if (manager->error)
	{
		write(2, "Error\n", 6);
		ft_free_manager(manager);
		exit(1);
	}
	return (manager);
}

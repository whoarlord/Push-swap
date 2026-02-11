/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:50:23 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 10:59:27 by iarrien-         ###   ########.fr       */
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
	if (!a->nums)
		return (NULL);
	b->nums = ft_calloc(size, sizeof(int));
	if (!b->nums)
		return (ft_free_stack(a), NULL);
	while (numstr[i])
	{
		a->nums[i] = ft_atoi(numstr[i]);
		i++;
	}
	a->index = ft_calloc(size, sizeof(int));
	if (!a->index)
		return (ft_free_stack(a), ft_free_stack(b), NULL);
	b->index = ft_calloc(size, sizeof(int));
	if (!b->index)
		return (ft_free_stack(a), ft_free_stack(b), NULL);
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

t_manager	*ft_fill_manager(int argc, char *argv[])
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
			ft_which_flag(manager, argv[i]);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 18:07:06 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (free(a), NULL);
	while (numstr[i])
	{
		a->nums[i] = ft_atoi(numstr[i]);
		i++;
	}
	return (a);
}

int	ft_validate_nums(char **numstr)
{
	int		size;
	int		i;
	char	*str;

	size = 0;
	if (!numstr)
		return (0);
	while (*numstr)
	{
		i = 0;
		str = *numstr;
		while (str[i])
		{
			if (!ft_isdigit(str[i]) && !(i == 0 && str[i] == '-'))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			i++;
		}
		size++;
		numstr++;
	}
	return (size);
}

void	ft_free_manager(t_manager *manager)
{
	while (*(manager->numbers))
	{
		free(*(manager->numbers));
		manager->numbers++;
	}
	free(manager);
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

static void	ft_strjoin_array(t_manager *manager, char *input)
{
	int		i;
	int		size;
	char	**new_array;

	i = 0;
	size = 0;
	while ((manager->numbers)[size])
		size++;
	new_array = malloc((size + 2) * sizeof(char *));
	if (!new_array)
	{
		manager->error = 1;
		return ;
	}
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
	new_array[size] = ft_strdup(input);
	new_array[size + 1] = NULL;
	free(manager->numbers);
	manager->numbers = new_array;
}

t_manager	*ft_fill_manager(int argc, char *argv[])
{
	int			i;
	t_manager	*manager;

	i = 1;
	manager = ft_calloc(1, sizeof(t_manager));
	manager->numbers = ft_calloc(1, sizeof(char *));
	if (!manager)
		return (NULL);
	while (i < argc || manager->error)
	{
		if (ft_strnstr(argv[i], "--", 2))
			ft_which_flag(manager, argv[i]);
		else if (!(manager->numbers)[0])
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

int	main(int argc, char *argv[])
{
	t_manager	*manager;
	int			size;

	manager = ft_fill_manager(argc, argv);
	size = ft_validate_nums(manager->numbers);
	ft_printf("nº de args: %d\n flags:%d\n", size, manager->algorithm);
	ft_free_manager(manager);
}

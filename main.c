/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 18:08:11 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_manager	*manager;
	int			size;

	manager = ft_fill_manager(argc, argv);
	size = ft_validate_nums(manager->numbers);
	ft_printf("nº de args: %d\n flags:%d\n", size, manager->algorithm);
	ft_free_manager(manager);
}

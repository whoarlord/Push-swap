/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 18:05:12 by iarrien-         ###   ########.fr       */
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
	int			i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
			i++;
		}
		ft_validate_nums(&argv[1]);
	}
	manager = ft_fill_manager(argc, argv);
	ft_free_manager(manager);
}

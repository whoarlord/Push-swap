/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 13:34:39 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"

int	ft_validate_nums(char **str_array)
{
	int		size;
	int		i;
	char	*str;

	size = 0;
	if (!str_array)
		return (0);
	while (*str_array)
	{
		i = 0;
		str = *str_array;
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
		str_array++;
	}
	return (size);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
			i++;
		}
		ft_printf("Total numbers to sort: %d\n", ft_validate_nums(&argv[1]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:04:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 15:55:08 by shierro          ###   ########.fr       */
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
		ft_validate_nums(&argv[1]);
	}
}

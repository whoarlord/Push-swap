/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:42:52 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:40:14 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(char c, int *i)
{
	int	result;

	result = 0;
	if (c == '-')
	{
		*i = *i + 1;
		result = 1;
	}
	else if (c == '+')
		*i = *i + 1;
	return (result);
}

static int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	negative;

	i = ft_isspace(nptr);
	result = 0;
	negative = ft_isnegative(nptr[i], &i);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
		{
			break ;
		}
		result = result * 10;
		result = result + nptr[i] - 48;
		i++;
	}
	if (negative)
		result = result * -1;
	return (result);
}
/*int	main()
{
	char	*nbr = NULL;

	printf("String: %s, Number: %d \n", nbr, ft_atoi(nbr));
}*/

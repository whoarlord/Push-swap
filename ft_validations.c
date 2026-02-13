/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:21:56 by shierro           #+#    #+#             */
/*   Updated: 2026/02/13 11:22:59 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doubles(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate_numinput(char **numstr)
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
			if (!ft_isdigit(str[i]) && !(i == 0 && (str[i] == '-'
						|| str[i] == '+')))
				return (0);
			i++;
		}
		size++;
		numstr++;
	}
	return (size);
}

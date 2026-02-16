/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:55:27 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/16 14:00:30 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_disorder_chars2(float disorder, char *result)
{
	if (disorder < 10)
	{
		write(2, "0", 1);
		write(2, ".", 1);
		write(2, "0", 1);
		write(2, result, 1);
	}
	else if (disorder < 100)
	{
		write(2, "0", 1);
		write(2, ".", 1);
		write(2, result, 2);
	}
	else if (disorder < 1000)
	{
		write(2, result, 1);
		write(2, ".", 1);
		write(2, &result[1], 2);
	}
}

static void	ft_print_disorder_chars(float disorder, char *result)
{
	if (disorder == 0)
	{
		write(2, result, 1);
		write(2, ".", 1);
		write(2, result, 1);
		write(2, result, 1);
	}
	else if (disorder == 10000)
	{
		write(2, result, 3);
		write(2, ".", 1);
		write(2, &result[1], 2);
	}
	else if (disorder < 1000)
		ft_print_disorder_chars2(disorder, result);
	else
	{
		write(2, result, 2);
		write(2, ".", 1);
		write(2, &result[2], 2);
	}
}

int	ft_print_disorder(float disorder)
{
	char	*result;

	disorder = disorder * 10000;
	result = ft_itoa(disorder);
	if (!result)
		return (1);
	ft_print_disorder_chars(disorder, result);
	ft_putchar_fd('%', 2);
	free(result);
	return (0);
}

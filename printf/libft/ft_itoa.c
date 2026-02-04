/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:37:59 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/21 11:48:11 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculatedigits(long n)
{
	int	result;

	result = 1;
	while (n > 9)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void	putnbr_itoa(long n, char **result, int len)
{
	int	n_temp;

	if (n > 9)
	{
		n_temp = n / 10;
		putnbr_itoa(n_temp, result, len - 1);
	}
	result[0][len] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	int		len;
	long	nl;

	is_negative = 0;
	nl = n;
	if (nl < 0)
	{
		is_negative = 1;
		nl = nl * -1;
	}
	len = calculatedigits(nl);
	result = (char *) ft_calloc(is_negative + len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	putnbr_itoa(nl, &result, len - 1 + is_negative);
	return (result);
}
/*int	main()
{
	int	i = -2147483648;
	char	*res;

	res = ft_itoa(i);
	printf("integer: %d, result: %s", i, res);
	free(res);
}*/

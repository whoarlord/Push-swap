/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:46:11 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/30 10:50:40 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1), 6);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_printptr(unsigned long long nb)
{
	int		size;
	char	*result;

	size = ft_calculate_digits_hex(nb);
	result = ft_number_to_base(nb, size, "0123456789abcdef");
	if (*result == '0')
		return (ft_putstr_fd("(nil)", 1), 5);
	size = size + 2;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(result, 1);
	return (size);
}

int	ft_printnbr(int nb)
{
	int		size;
	long	nb2;

	nb2 = nb;
	size = 0;
	if (nb2 < 0)
	{
		nb2 = nb2 * -1;
		size++;
	}
	size = size + ft_calculate_digits((unsigned int)nb2);
	ft_putnbr_fd(nb, 1);
	return (size);
}

int	ft_print_unnbr(unsigned int nb)
{
	int		size;
	char	*result;

	size = ft_calculate_digits(nb);
	result = ft_number_to_base(nb, size, "0123456789");
	ft_putstr_fd(result, 1);
	return (size);
	return (size);
}

int	ft_print_hex(unsigned int nb, const char *s)
{
	int		size;
	char	*result;

	size = ft_calculate_digits_hex(nb);
	result = ft_number_to_base(nb, size, s);
	ft_putstr_fd(result, 1);
	return (size);
}

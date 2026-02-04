/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:39:17 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 13:07:40 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calculate_digits_hex(unsigned long long nb)
{
	int	result;

	result = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		result++;
	}
	return (result);
}

int	ft_calculate_digits(unsigned int nb)
{
	int	result;

	result = 1;
	while (nb > 10)
	{
		nb = nb / 10;
		result++;
	}
	return (result);
}

char	*ft_number_to_base(unsigned long long nb, int size, const char *base)
{
	char	*result;
	int		i;
	int		base_size;

	i = 1;
	result = (char *)malloc(size + 1);
	base_size = ft_strlen(base);
	while (nb > (unsigned long long)base_size)
	{
		result[size - i] = base[(nb % base_size)];
		i++;
		nb = nb / base_size;
	}
	result[size - i] = base[(nb % base_size)];
	result[size] = '\0';
	return (result);
}

int	check_type(va_list vargs, char const c)
{
	int	result;

	result = 0;
	if (c == 'c')
	{
		result = 1;
		ft_putchar_fd(va_arg(vargs, int), 1);
	}
	if (c == 's')
		result = ft_printstr(va_arg(vargs, char *));
	if (c == 'p')
		result = ft_printptr(va_arg(vargs, unsigned long));
	if (c == 'd' || c == 'i')
		result = ft_printnbr(va_arg(vargs, int));
	if (c == 'u')
		result = ft_print_unnbr(va_arg(vargs, unsigned int));
	if (c == 'x')
		result = ft_print_hex(va_arg(vargs, unsigned int), "0123456789abcdef");
	if (c == 'X')
		result = ft_print_hex(va_arg(vargs, unsigned int), "0123456789ABCDEF");
	return (result);
}

int	ft_printf(char const *s, ...)
{
	int		result;
	va_list	vargs;

	va_start(vargs, s);
	result = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				result = result + write(1, s, 1);
			else
				result = result + check_type(vargs, s[0]);
		}
		else
		{
			write(1, s, 1);
			result++;
		}
		s++;
	}
	va_end(vargs);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:13:32 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 13:21:19 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

char	*ft_number_to_base(unsigned long long nb, int size, const char *base);
int		ft_printstr(char *s);
int		ft_printptr(unsigned long long nb);
int		ft_printnbr(int nb);
int		ft_print_unnbr(unsigned int nb);
int		ft_calculate_digits_hex(unsigned long long nb);
int		ft_calculate_digits(unsigned int nb);
int		check_type(va_list vargs, char const c);
int		ft_printf(char const *s, ...);
int		ft_print_hex(unsigned int nb, const char *s);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:29:17 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 16:25:49 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(long n, int fd)
{
	long	n2;

	n2 = 0;
	if (n > 9)
	{
		n2 = n / 10;
		ft_putnbr_rec(n2, fd);
	}
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	if (fd == -1)
		return ;
	nl = n;
	if (nl < 0)
	{
		nl = nl * -1;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_rec(nl, fd);
}
/* int	main()
{
	int	des;

	des = open("tests.txt", O_WRONLY);
	printf("%d", des);
	ft_putnbr_fd(-2147483648, des);
	close(des);
} */

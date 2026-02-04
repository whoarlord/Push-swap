/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:09:36 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/19 16:01:32 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, sizeof(c));
}
/*int	main()
{
	int	fd;

	fd = open("testss.txt", O_WRONLY);
	printf("%d", fd);
	ft_putchar_fd('a', fd);
	close(fd);
}*/

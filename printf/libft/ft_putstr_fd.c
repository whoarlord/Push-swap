/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:06:35 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/20 18:02:38 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd == -1)
		return ;
	write(fd, s, ft_strlen(s));
}
/*int	main()
{
	int	des;

	des = open("tests.txt", O_WRONLY);
	printf("%d", des);
	ft_putstr_fd("sdaf", des);
	close(des);
}*/

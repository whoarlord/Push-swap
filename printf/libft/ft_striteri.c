/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:49:01 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/19 15:57:04 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	ft_aux2(unsigned int n, char *c)
{
	*c = *c + n;
}
int	main()
{
	char	src[] = "aaaa";

	ft_striteri(src, &ft_aux2);
	printf("res: %s", src);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:54:07 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:28:29 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) c == str[i])
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
/*int	main()
{
	char	*str = "Hoolads";
	char	str2[] = "Hoolads";

	printf("After: %s, Before: %p\n", str,
		ft_memchr((void *) str, 'l', 0));
	printf("s1: %s, s2: %s, difference: %d",
		str, str2, ft_memcmp((void *) str, (void *) str2, 9));
}*/

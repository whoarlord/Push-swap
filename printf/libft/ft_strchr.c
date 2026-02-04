/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:51:45 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:44:09 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char) c == *s)
		{
			return ((char *) s);
		}
		s++;
	}
	if (*s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}
/*int	main()
{
	const char	*s = "Hola mundo buenos dias Ooisjadi";
	char	c = '\0';

	printf("the original string: %s,the
	first ocurrency: %s\n", s, ft_strchr(s, c));
	printf("the original string: %s,the
	last ocurrency: %s", s, ft_strrchr(s, c));
}*/

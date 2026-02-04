/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:34:20 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:11:11 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	result;
	size_t	index;

	result = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (result);
	while (index < size - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (result);
}

/* int	main()
{
	char *dest = ft_calloc(15, 1);
	size_t i;

	ft_memset(dest, 'r', 6);
	i = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("len %d, string: %s", (int) i, dest);
} */

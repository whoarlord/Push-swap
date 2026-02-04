/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:26:46 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:25:15 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*result;
	const unsigned char	*source;
	size_t				index;

	result = (unsigned char *) dest;
	source = (const unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	index = 0;
	while (index < n)
	{
		result[index] = source[index];
		index++;
	}
	return (dest);
}
/*int	main()
{
	unsigned char	src[] = "Hola buenos dias";
	//char	*src = NULL;
	unsigned char	dest1[20];
	unsigned char	*dest1res;

	dest1res = (unsigned char *)ft_memcpy((void *)&dest1[0], (const void *)
								 &src[0], 0);
	printf("src: %s, dest: %s\n", &src[0], dest1res);
}*/

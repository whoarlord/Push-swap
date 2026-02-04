/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:15:54 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:26:07 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (const unsigned char *) src;
	if (!dest2 && !src2)
		return (NULL);
	if (dest2 < src2)
		dest2 = ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	return (dest);
}
/*int	main()
{
	unsigned char	*src = (unsigned char *)
	malloc(sizeof(unsigned char) * 17);
	//char dest[20];
	ft_strlcpy((char *) src, "Hola buenos dias", 17);
	unsigned char *dest1res;

	dest1res = (unsigned char *) ft_memmove((void *)
	&src[1], (const void *) &src[0], 15);
	printf("%s\n", dest1res);
	printf("%s\n", src);
	free(src);
}*/

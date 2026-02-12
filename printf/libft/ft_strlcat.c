/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:37:50 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:03:12 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	dst_length;

	dst_length = ft_strlen(dst);
	length = dst_length + ft_strlen(src);
	if (size < dst_length + 1)
		return (size + ft_strlen(src));
	ft_strlcpy(&dst[dst_length], src, size - dst_length);
	return (length);
}
/* int	main()
{
	char dst1[10];
	size_t len;

	dst1[0] = 'a';
	len = ft_strlcat(dst1, "lorem ipsum dolor sit amet", 10);
	printf("(strlcat) len: %d, string: %s", (int) len, &dst1[0]);
}*/

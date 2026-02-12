/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:00:36 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/21 14:00:37 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			index;

	result = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		result[index] = c;
		index++;
	}
	return (s);
}
/*int	main()
{
	unsigned char	test1[] = "asadg";

	printf("After: %s\n", test1);
	printf("Before: %s", (unsigned char *) ft_memset((void *) test1, 'a', 3));
}*/

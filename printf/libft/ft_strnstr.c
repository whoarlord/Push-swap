/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:33:33 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:19:01 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*result;
	size_t	i;
	size_t	lenlit;

	result = NULL;
	i = 0;
	lenlit = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *) big);
	while ((i + lenlit - 1) < len && ft_strlen(big) >= (i + lenlit))
	{
		if (big[i] == *little)
		{
			if (ft_strncmp(&big[i], little, lenlit) == 0)
			{
				result = (char *) &big[i];
				break ;
			}
		}
		i++;
	}
	return (result);
}
/* int	main()
{
	printf("result: %s", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
} */

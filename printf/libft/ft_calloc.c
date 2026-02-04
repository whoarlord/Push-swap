/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 19:29:39 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/21 11:43:42 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	i;

	if (!size || !nmemb)
		return (malloc(1));
	result = (char *) malloc(size * nmemb);
	if (!result)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		result[i] = '\0';
		i++;
	}
	return ((void *) result);
}
/*int	main()
{
	char	*result;

	result = (char *) ft_calloc(6, sizeof(char));
	if (result == NULL)
		printf("%p\n", result);
	write(1, result, 1);
	free(result);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:47:50 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/21 13:59:24 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		length;

	length = ft_strlen(s) + 1;
	result = (char *) malloc(sizeof(char) * length);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, length);
	return (result);
}
/*int	main()
{
	char *str = "Hola";
	char *result;

	result = ft_strdup(str);
	printf("%p: %s\n", result, result);
	free(result);
}*/

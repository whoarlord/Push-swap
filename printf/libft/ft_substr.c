/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:35:20 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 13:46:08 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
/*int	main(void)
{
	char	*s;
	char	*result;

	s = (char *) malloc(sizeof(char) * 10);
	ft_strlcpy(s, "Hola buen", 10);
	result = ft_substr((char const *) s, 10, 3);
	printf("First: %s, Result: %s", s, result);
	free(s);
	free(result);
}*/

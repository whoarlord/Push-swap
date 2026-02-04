/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:33:03 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/20 19:22:38 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

/*char	ft_aux(unsigned int n, char c)
{
	return (c + n);
}

int	main()
{
	const char	*src = "asdanj";
	char	*result;

	result = ft_strmapi(src, &ft_aux);
	printf("result: %p\n", result);
	printf("result: %s", result);
	free(result);
}*/

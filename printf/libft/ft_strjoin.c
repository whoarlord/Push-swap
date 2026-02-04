/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:12:30 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/19 15:11:13 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, lens1 + 1);
	ft_strlcpy(&result[lens1], s2, lens2 + 1);
	return (result);
}
/*int	main()
{
	char	*s1 = "";
	char	*s2 = "Adios";
	char	*result;

	result = ft_strjoin(s1, s2);
	printf("S1: %s, S2: %s, Result: %s", s1, s2, result);
	free(result);
}
*/

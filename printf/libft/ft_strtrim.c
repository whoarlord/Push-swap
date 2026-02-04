/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:38:14 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/20 15:29:29 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if c exist in set return 0, if not return 1
static int	ft_strcount(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (0);
		set++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (ft_strcount(set, s1[i]))
			break ;
		i++;
	}
	while (j > i)
	{
		if (ft_strcount(set, s1[j]))
			break ;
		j--;
	}
	result = ft_substr(s1, i, j - i + 1);
	if (result == NULL)
		return (NULL);
	return (result);
}
/*int	main()
{
	const char	*s1 = "AbaaaAbabba";
	const char	*set = "abA";
	char	*result;

	result = ft_strtrim(s1, set);
	printf("S1: %s, set: %s, result: %s", s1, set, result);
	free(result);
}*/

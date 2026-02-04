/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:02:41 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 14:37:51 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchr(char const *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
		{
			result++;
		}
		s++;
	}
	return (result);
}

static void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free[i]);
	free(to_free);
}

static int	ft_splitaux(char const *s, char c, char **result)
{
	int	i;
	int	word_length;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_length = 0;
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			word_length++;
		}
		result[j] = ft_substr(s, i - word_length, word_length);
		if (!result[j])
			return (ft_free(result), 1);
		j++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		len;

	if (!s)
		return (NULL);
	len = ft_countchr(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	if (ft_splitaux(s, c, result))
		return (NULL);
	result[len] = NULL;
	return (result);
}
/* int	main()
{
	char	**str;
	int	i = 0;

	str = ft_split("HOLA MUNDO", '\0');
	printf("\npointer: %p\n", str);
	if (str != NULL)
	{
		while (str[i])
		{
			printf("String %d : %s\n", i, str[i]);
			i++;
		}
		i = 0;
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:10:28 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 13:08:18 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_memory(char *f_buffer)
{
	char	*result;
	int		len;

	len = 0;
	while (f_buffer[len] && f_buffer[len] != '\n')
	{
		len++;
	}
	if (f_buffer[len] == '\n')
		len++;
	result = (char *)malloc((len + 1) * sizeof(char));
	return (result);
}

void	fill_result(char *result, char *f_buffer, int *i)
{
	int		j;

	j = 0;
	while (f_buffer[*i] && f_buffer[*i] != '\n')
	{
		result[j] = f_buffer[*i];
		*i = *i + 1;
		j++;
	}
	if (f_buffer[*i] == '\n')
	{
		result[j] = '\n';
		j++;
		*i = *i + 1;
	}
	result[j] = '\0';
}

char	*ft_strjoin_line(char *dest, char *src)
{
	char	*result;
	int		i;
	int		total_len;
	int		j;

	total_len = ft_strlen(dest) + ft_strlen(src);
	result = malloc((total_len + 1) * sizeof(char));
	j = 0;
	i = 0;
	while (i < total_len && dest[j])
	{
		result[i] = dest[j];
		i++;
		j++;
	}
	j = 0;
	while (i < total_len && src[j])
	{
		result[i] = src[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (free(dest), result);
}

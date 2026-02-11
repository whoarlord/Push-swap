/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:59:51 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 13:08:02 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_line_loop(int fd,
	char f_buffer[BUFFER_SIZE + 1], char **result, int *i)
{
	int		first;
	char	*temp;

	first = 1;
	temp = NULL;
	while ((*result)[ft_strlen(*result) - 1 + first] != '\n')
	{
		first = 0;
		if (!f_buffer[*i])
		{
			*i = read(fd, f_buffer, BUFFER_SIZE);
			f_buffer[*i] = '\0';
			if (*i <= 0)
				break ;
			*i = 0;
		}
		free(temp);
		temp = alloc_memory(&f_buffer[*i]);
		if (!temp)
			return ;
		fill_result(temp, f_buffer, i);
		*result = ft_strjoin_line(*result, temp);
	}
	free(temp);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	f_buffer[BUFFER_SIZE + 1];
	static int	i = BUFFER_SIZE;

	result = malloc(1);
	if (fd == -1)
		return (NULL);
	result[0] = '\0';
	get_line_loop(fd, f_buffer, &result, &i);
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	return (result);
}

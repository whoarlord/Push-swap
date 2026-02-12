/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:02:24 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/11 14:48:48 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*get_next_line(int fd);
char	*alloc_memory(char *f_buffer);
void	fill_result(char *result, char *f_buffer, int *i);
char	*ft_strjoin_line(char *dest, char *src);
void	get_line_loop(int fd,
			char f_buffer[BUFFER_SIZE + 1], char **result, int *i);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:43:02 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/21 12:40:33 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *a)
{
	size_t	result;

	result = 0;
	while (*a)
	{
		result++;
		a++;
	}
	return (result);
}
/*
int	main()
{
	char *str = NULL;
	size_t len;

	len = ft_strlen(str);
	if (len == (size_t) NULL)
		printf("NULL");
	printf("%d", (int) len);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:08:56 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/17 11:28:28 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_join_splits(char **result, char **to_join)
{
	int	i;

	i = 0;
	while ((to_join)[i])
	{
		result[i] = ft_strdup((to_join)[i]);
		if (!result[i])
			return (1);
		i++;
	}
	return (0);
}

static char	**ft_fill_array(t_manager *manager, char **new_array)
{
	int		i;
	int		j;
	int		len;
	char	**result;

	i = 0;
	while ((manager->numbers)[i])
		i++;
	len = i;
	j = i;
	i = 0;
	while (new_array[i])
		i++;
	len = len + i;
	result = malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (ft_free_split(new_array), ft_free_all(manager, NULL, NULL, 1),
			NULL);
	i = 0;
	if (ft_join_splits(result, manager->numbers))
		return (ft_free_split(new_array), ft_free_split(result), NULL);
	if (ft_join_splits(&result[j], new_array))
		return (ft_free_split(new_array), ft_free_split(result), NULL);
	result[len] = NULL;
	return (result);
}

void	ft_strjoin_array(t_manager *manager, char *input)
{
	int		size;
	char	**new_array;
	char	**result;

	size = 0;
	while ((manager->numbers)[size])
		size++;
	new_array = ft_split(input, ' ');
	if (!new_array)
		ft_free_all(manager, NULL, NULL, 1);
	if (!new_array[0])
	{
		ft_free_split(new_array);
		ft_free_all(manager, NULL, NULL, 1);
	}
	result = ft_fill_array(manager, new_array);
	if (!result)
		ft_free_all(manager, NULL, NULL, 1);
	if (manager->error)
		return ;
	ft_free_split(manager->numbers);
	ft_free_split(new_array);
	manager->numbers = result;
}

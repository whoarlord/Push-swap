/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:05:05 by iarrien-          #+#    #+#             */
/*   Updated: 2026/02/04 18:05:22 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_manager(t_manager *manager)
{
	while (*(manager->numbers))
	{
		free(*(manager->numbers));
		manager->numbers++;
	}
	free(manager);
}

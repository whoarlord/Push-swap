/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_borders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shierro <shierro@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:49:27 by shierro           #+#    #+#             */
/*   Updated: 2026/02/05 17:06:38 by shierro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_borders	*ft_get_borders(t_stack *a, t_borders *borders)
{
	int	i;

	i = 1;
	borders->min = a->nums[0];
	borders->max = a->nums[0];
	while (i < a->size)
	{
		if (a->nums[i] < borders->min)
		{
			borders->min = a->nums[i];
			borders->minindex = i;
		}
		else if (a->nums[i] > borders->max)
		{
			borders->max = a->nums[i];
			borders->maxindex = i;
		}
		i++;
	}
	return (borders);
}

void	ft_min_closer_to_start(t_stack *a, t_stack *b, t_borders *borders)
{
	// ft_printf("uno\n");
	while (a->nums[0] != borders->min)
	{
		ft_printf("%s\n", ft_rotate_reverse(a));
		borders->maxindex--;
	}
	ft_printf("%s\n", ft_push(b, a));
	while (a->nums[0] != borders->max)
	{
		if ((borders->maxindex < a->size / 2))
			ft_printf("%s\n", ft_rotate_reverse(a));
		else
			ft_printf("%s\n", ft_rotate(a));
	}
	ft_printf("%s\n", ft_push(b, a));
}

void	ft_max_closer_to_end(t_stack *a, t_stack *b, t_borders *borders)
{
	// ft_printf("dos\n");
	while (a->nums[0] != borders->max)
	{
		ft_printf("%s\n", ft_rotate(a));
		borders->minindex++;
	}
	ft_printf("%s\n", ft_push(b, a));
	while (a->nums[0] != borders->min)
	{
		if ((borders->minindex < a->size / 2))
			ft_printf("%s\n", ft_rotate_reverse(a));
		else
			ft_printf("%s\n", ft_rotate(a));
	}
	ft_printf("%s\n", ft_push(b, a));
}

void	ft_max_closer_to_start(t_stack *a, t_stack *b, t_borders *borders)
{
	// ft_printf("tres\n");
	while (a->nums[0] != borders->max)
	{
		ft_printf("%s\n", ft_rotate_reverse(a));
		borders->minindex--;
	}
	ft_printf("%s\n", ft_push(b, a));
	while (a->nums[0] != borders->min)
	{
		if ((borders->minindex < a->size / 2))
			ft_printf("%s\n", ft_rotate_reverse(a));
		else
			ft_printf("%s\n", ft_rotate(a));
	}
	ft_printf("%s\n", ft_push(b, a));
}

void	ft_min_closer_to_end(t_stack *a, t_stack *b, t_borders *borders)
{
	// ft_printf("cuatro\n");
	while (a->nums[0] != borders->min)
	{
		ft_printf("%s\n", ft_rotate(a));
		borders->maxindex--;
	}
	ft_printf("%s\n", ft_push(b, a));
	while (a->nums[0] != borders->max)
	{
		if ((borders->maxindex < a->size / 2))
			ft_printf("%s\n", ft_rotate_reverse(a));
		else
			ft_printf("%s\n", ft_rotate(a));
	}
	ft_printf("%s\n", ft_push(b, a));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:42:32 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/22 12:51:27 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		if (!new->content)
		{
			free(new);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new);
		lst = lst->next;
	}
	return (result);
}
/*
void	*ft_modify_content(void *content)
{
	char	*mod;
	char *temp;

	temp = (char *) content;
	if (!temp)
		return (NULL);
	mod = ft_strdup((char *) content);
	mod[1] = 'b';
	return (mod);
}*/

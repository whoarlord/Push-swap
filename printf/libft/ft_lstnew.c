/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrien- <iarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:23:50 by iarrien-          #+#    #+#             */
/*   Updated: 2026/01/20 19:23:49 by iarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}
/*int	main()
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new;
	t_list	*temp;
	t_list	*back;
	t_list *final;

	char *str1 = ft_strdup("str1");
	char    *str2 = ft_strdup("str2");
	char    *str3 = ft_strdup("str3");
	char    *str4 = ft_strdup("str4");
	char    *str5 = ft_strdup("str5");

	lst1 = ft_lstnew((void *) str1);
	lst2 = ft_lstnew((void *) str2);
	lst3 = ft_lstnew((void *) str3);
	new = ft_lstnew((void *) str4);
	temp = lst1;
	back = ft_lstnew((void *) str5);

	lst1->next = lst2;
	lst2->next = lst3;

	printf("Before: ");
	while (temp)
	{
		printf("content: %s ", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstadd_front(&lst1, new);
	temp = lst1;
	printf("After: ");
	while (temp)
	{
		printf("content: %s ", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	temp = ft_lstlast(lst1);
	printf("Last: %s, next to Last: %s\n", (char *)
	temp->content, (char *) temp->next);
	ft_lstadd_back(&lst1, back);
	temp = lst1;
	printf("Added: ");
	while (temp)
	{
		printf("content: %s ", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	ft_lstiter(lst1, &ft_modify);
	printf("Modified with ft_lstiter: ");
	temp = lst1;
	while (temp)
	{
		printf("content: %s ", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	final = ft_lstmap(lst1, &ft_modify_content, &ft_delete);
	printf("Modified with ft_lstmap: ");
	temp = final;
	while (temp)
	{
		printf("content: %s ", (char *) temp->content);
		temp = temp->next;
	}
	printf("\n");
	printf("size of final: %d\n", ft_lstsize(final));
	ft_lstclear(&final, &ft_delete);
	ft_lstclear(&lst1, &ft_delete);
	printf("%p\n", final);
}*/

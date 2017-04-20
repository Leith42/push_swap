/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 10:29:43 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 00:01:16 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list "lst" and applies the function "f" to each link to create
 * a “fresh” list (using malloc(3)) resulting from the successive applications 
 * of "f". If the allocation fails, the function returns NULL.
 */

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prev_list;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(lst->content, lst->content_size);
	if (!new_list)
		return (NULL);
	new_list = f(lst);
	prev_list = new_list;
	while (lst->next)
	{
		prev_list->next = f(lst->next);
		prev_list = prev_list->next;
		lst = lst->next;
	}
	return (new_list);
}

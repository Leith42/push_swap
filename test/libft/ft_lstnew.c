/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:01:12 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 21:47:01 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a “fresh” link. The variables content
 * and content_size of the new link are initialized by copy of the parameters
 * of the function. If the parameter "content" is null, the variable "content"
 * is initialized to NULL and the variable "content_size" is initialized to 0
 * even if the parameter "content_size" isn’t. The variable "next"
 * is initialized to NULL. If the allocation fails, the function returns NULL.
 */

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if (!(new_list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size > 0)
	{
		if(!(new_list->content = ft_memalloc(content_size)))
		{
			free(new_list);
			return (NULL);
		}
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	new_list->next = NULL;
	return (new_list);
}

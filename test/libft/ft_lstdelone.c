/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:29:43 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 22:41:53 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes as a parameter a link’s pointer address and frees the memory of the
 * link’s content using the function "del" given as a parameter, then frees the
 * link’s memory using free(3). The memory of "next" must not be freed under
 * any circumstance. Finally, the pointer to the link that was just freed
 * must be set to NULL.
 */

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !(*alst))
		return ;
	if (del)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

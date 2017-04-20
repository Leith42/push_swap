/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:58:17 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 23:09:37 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the element "new" to the beginnning of the list. */

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!(*alst) || new || alst)
			new->next = *alst;
		*alst = new;
}

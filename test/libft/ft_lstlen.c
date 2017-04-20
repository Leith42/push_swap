/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simzam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:35:22 by simzam            #+#    #+#             */
/*   Updated: 2016/05/17 23:46:47 by simzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *blist)
{
	int		i;
	t_list	*list;

	i = 0;
	if (blist)
	{
		list = blist;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

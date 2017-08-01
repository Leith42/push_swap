/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reducer_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:54:53 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 15:28:43 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_we_delete(t_list *i)
{
	if (!ft_strcmp(i->content, PUSH_A) && !ft_strcmp(i->next->content, PUSH_B))
		return (true);
	if (!ft_strcmp(i->content, PUSH_B) && !ft_strcmp(i->next->content, PUSH_A))
		return (true);
	if (!ft_strcmp(i->content, ROT_A) && !ft_strcmp(i->next->content, REVROT_A))
		return (true);
	if (!ft_strcmp(i->content, REVROT_A) && !ft_strcmp(i->next->content, ROT_A))
		return (true);
	if (!ft_strcmp(i->content, ROT_B) && !ft_strcmp(i->next->content, REVROT_B))
		return (true);
	if (!ft_strcmp(i->content, REVROT_B) && !ft_strcmp(i->next->content, ROT_B))
		return (true);
	return (false);
}

char	*do_we_cut(t_list *i)
{
	if (!ft_strcmp(i->content, SWAP_A) && !ft_strcmp(i->next->content, SWAP_B))
		return (SWAP_BOTH);
	if (!ft_strcmp(i->content, SWAP_B) && !ft_strcmp(i->next->content, SWAP_A))
		return (SWAP_BOTH);
	if (!ft_strcmp(i->content, ROT_A) && !ft_strcmp(i->next->content, ROT_B))
		return (ROT_BOTH);
	if (!ft_strcmp(i->content, ROT_B) && !ft_strcmp(i->next->content, ROT_A))
		return (ROT_BOTH);
	if (!ft_strcmp(i->content, REVROT_A) &&
		!ft_strcmp(i->next->content, REVROT_B))
		return (REVROT_BOTH);
	if (!ft_strcmp(i->content, REVROT_B) &&
		!ft_strcmp(i->next->content, REVROT_A))
		return (REVROT_BOTH);
	return (NULL);
}

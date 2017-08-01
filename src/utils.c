/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 13:38:40 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 14:06:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stock_instruction(t_list **inst, char *str)
{
	t_list	*tmp;

	tmp = *inst;
	if (*inst == NULL)
	{
		*inst = ft_lstnew(str, ft_strlen(str) + 1);
	}
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = ft_lstnew(str, ft_strlen(str) + 1);
	}
}

void	do_we_swap(t_stack **a, t_stack **b, t_list **inst)
{
	if (a && *a && (*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
		{
			exec_instruction(SWAP_A, a, b, inst);
		}
	}
	if (b && *b && (*b)->next)
	{
		if ((*b)->data < (*b)->next->data)
		{
			exec_instruction(SWAP_B, a, b, inst);
		}
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:24:42 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 14:25:17 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		next_inst(char *command, t_stack **a, t_stack **b)
{
	if (ft_strcmp(command, ROT_B) == 0)
		return (rotate(b, NULL));
	else if (ft_strcmp(command, ROT_BOTH) == 0)
		return (rotate(a, b));
	else if (ft_strcmp(command, REVROT_A) == 0)
		return (revrot(a, NULL));
	else if (ft_strcmp(command, REVROT_B) == 0)
		return (revrot(b, NULL));
	else if (ft_strcmp(command, REVROT_BOTH) == 0)
		return (revrot(a, b));
	else
		return (false);
}

int		exec_instruction(char *command, t_stack **a, t_stack **b, t_list **inst)
{
	if (inst != NULL)
		stock_instruction(inst, command);
	if (ft_strcmp(command, SWAP_A) == 0)
		swap(*a, NULL);
	else if (ft_strcmp(command, SWAP_B) == 0)
		swap(*b, NULL);
	else if (ft_strcmp(command, SWAP_BOTH) == 0)
		swap(*a, *b);
	else if (ft_strcmp(command, PUSH_A) == 0)
		return (push(a, b));
	else if (ft_strcmp(command, PUSH_B) == 0)
		return (push(b, a));
	else if (ft_strcmp(command, ROT_A) == 0)
		return (rotate(a, NULL));
	else
		return (next_inst(command, a, b));
	return (true);
}

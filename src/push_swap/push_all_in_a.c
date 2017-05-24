/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:38:17 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:38:32 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_all_in_a(t_stack **a, t_stack **b, t_list **inst)
{
	while (*b != NULL)
	{
		if (exec_instructions(PUSH_A, a, b) == false)
			return (false);
		stock_instruction(inst, PUSH_A);
	}
	return (true);
}

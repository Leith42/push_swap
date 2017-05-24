/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:32:31 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:38:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_we_swap(t_stack **a, t_stack **b, t_list **inst)
{
	if (*a && (*a)->next)
	{
		if ((*a)->data > (*a)->next->data)
		{
			if (exec_instructions(SWAP_A, a, b) == false)
				return (false);
			stock_instruction(inst, SWAP_A);
		}
	}
	return (true);
}

int		which_rotate(t_stack *s, int min)
{
	int len;
	int find;

	len = 0;
	find = 0;
	while (s != NULL)
	{
		if (s->data == min)
			find = len;
		len++;
		s = s->next;
	}
	return (len / 2 < find ? 0 : 1);
}

int		rot_min_to_head(t_stack **a, t_stack **b, t_list **inst)
{
	int min;
	int rot;

	min = get_min(*a);
	rot = which_rotate(*a, min);
	while (min != (*a)->data)
	{
		if (rot == 1)
		{
			if (exec_instructions(ROT_A, a, b) == false)
				return (false);
			stock_instruction(inst, ROT_A);
		}
		else
		{
			if (exec_instructions(REVROT_A, a, b) == false)
				return (false);
			stock_instruction(inst, REVROT_A);
		}
	}
	return (true);
}

int		check_lists_status(t_stack **a, t_stack **b)
{
	if (ascending_check(*a) == true)
	{
		if (*b && ascending_check(*b) == true)
			return (true);
		else if (*b && descending_check(*b) == true)
			return (true);
	}
	return (false);
}

int		push_swap(t_stack **a, t_stack **b, t_list **inst)
{
	int status;

	if (ascending_check(*a) == true)
		return (true);
	if (do_we_swap(a, b, inst) == false)
		return (false);
	while (*a != NULL)
	{
		if (rot_min_to_head(a, b, inst) == false)
			return (false);
		if ((status = check_lists_status(a, b)) == true)
			return (push_all_in_a(a, b, inst));
		else if (status == ERROR)
			return (false);
		if (exec_instructions(PUSH_B, a, b) == false)
			return (false);
		stock_instruction(inst, PUSH_B);
	}
	return (push_all_in_a(a, b, inst));
}

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

int		which_rotate(t_stack *s, int min)
{
	int len;
	int find;

	len = 0;
	find = 0;
	while (s != NULL)
	{
		if (s->data == min)
		{
			find = len;
		}
		len++;
		s = s->next;
	}
	return (len / 2 < find ? 0 : 1);
}

int		check_lists_status(t_stack **a, t_stack **b)
{
	if (ascending_check(*a) == true)
	{
		if ((*b == NULL) || (*b && (*b)->next == NULL)
			|| (descending_check(*b) == true))
		{
			return (true);
		}
	}
	return (false);
}

int	get_min(t_stack *s)
{
	int min;

	min = s->data;
	s = s->next;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
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
			if (exec_instruction(ROT_A, a, b, inst) == false)
			{
				return (false);
			}
		}
		else
		{
			if (exec_instruction(REVROT_A, a, b, inst) == false)
			{
				return (false);
			}
		}
	}
	return (true);
}

int		ps_ssort(t_stack **a, t_stack **b, t_list **inst)
{
	do_we_swap(a, NULL, inst);
	while (*a != NULL)
	{
		if (rot_min_to_head(a, b, inst) == false)
		{
			return (false);
		}
		if ((check_lists_status(a, b)) == true)
		{
			return (push_all_in_a(a, b, inst));
		}
		if (exec_instruction(PUSH_B, a, b, inst) == false)
		{
			return (false);
		}
	}
	return (push_all_in_a(a, b, inst));
}
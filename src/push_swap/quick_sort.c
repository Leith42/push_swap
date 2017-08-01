/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:19:52 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 15:25:11 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_push_and_rot(t_stack **a, t_stack **b, t_list **ins, t_qsort *qsort)
{
	int sorts;

	sorts = rev_how_many_sort(*b, qsort->pivot, qsort->len);
	while (sorts)
	{
		if ((*b)->data > qsort->pivot)
		{
			if (exec_instruction(PUSH_A, a, b, ins) == false)
			{
				handle_error(*a, *b, *ins, NULL);
			}
			qsort->push++;
			sorts--;
		}
		else
		{
			if (exec_instruction(ROT_B, a, b, ins) == false)
			{
				handle_error(*a, *b, *ins, NULL);
			}
			qsort->rot++;
		}
	}
}

void	ps_rev_qsort(t_stack **a, t_stack **b, t_list **inst, t_qsort qsort)
{
	qsort.push = 0;
	qsort.rot = 0;
	qsort.tmp_len = qsort.len;
	if (qsort.len <= 2)
	{
		return (do_we_swap(NULL, b, inst));
	}
	qsort.pivot = get_pivot(*b, qsort.len);
	rev_push_and_rot(a, b, inst, &qsort);
	qsort.len = qsort.push;
	ps_qsort(a, b, inst, qsort);
	qsort.big_len = stack_len(*b);
	while (qsort.rot-- && qsort.big_len != qsort.len)
	{
		if (exec_instruction(REVROT_B, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
	qsort.len = qsort.tmp_len - qsort.push;
	ps_rev_qsort(a, b, inst, qsort);
	while (qsort.push--)
	{
		if (exec_instruction(PUSH_B, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
}

void	push_and_rot(t_stack **a, t_stack **b, t_list **inst, t_qsort *qsort)
{
	int sorts;

	sorts = how_many_sorts(*a, qsort->pivot, qsort->len);
	while (sorts)
	{
		if ((*a)->data < qsort->pivot)
		{
			if (exec_instruction(PUSH_B, a, b, inst) == false)
				handle_error(*a, *b, *inst, NULL);
			qsort->len--;
			qsort->push++;
			sorts--;
		}
		else
		{
			if (exec_instruction(ROT_A, a, b, inst) == false)
			{
				handle_error(*a, *b, *inst, NULL);
			}
			qsort->rot++;
		}
	}
}

void	ps_qsort(t_stack **a, t_stack **b, t_list **inst, t_qsort qsort)
{
	qsort.push = 0;
	qsort.rot = 0;
	if (qsort.len <= 2)
	{
		return (do_we_swap(a, NULL, inst));
	}
	qsort.pivot = get_pivot(*a, qsort.len);
	push_and_rot(a, b, inst, &qsort);
	qsort.big_len = stack_len(*a);
	while (qsort.rot-- && qsort.big_len != qsort.len)
	{
		if (exec_instruction(REVROT_A, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
	ps_qsort(a, b, inst, qsort);
	qsort.len = qsort.push;
	ps_rev_qsort(a, b, inst, qsort);
	while (qsort.push--)
	{
		if (exec_instruction(PUSH_A, a, b, inst) == false)
			handle_error(*a, *b, *inst, NULL);
	}
}

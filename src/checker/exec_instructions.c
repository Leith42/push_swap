/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:09:52 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 12:20:26 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **a, t_stack **b, char *ins)
{
	int tmp;

	if ((ft_strcmp(ins, SWAP_A) == 0 || ft_strcmp(ins, SWAP_BOTH) == 0))
	{
		if (*a && (*a)->next)
		{
			tmp = (*a)->data;
			(*a)->data = (*a)->next->data;
			(*a)->next->data = tmp;
		}
	}
	if ((ft_strcmp(ins, SWAP_B) == 0 || ft_strcmp(ins, SWAP_BOTH) == 0))
	{
		if (*b && (*b)->next)
		{
			tmp = (*b)->data;
			(*b)->data = (*b)->next->data;
			(*b)->next->data = tmp;
		}
	}
	return (true);
}

int	push(t_stack **a, t_stack **b, char *ins)
{
	t_stack **dest;
	t_stack **src;

	src = ft_strcmp(ins, PUSH_A) == 0 ? b : a;
	dest = ft_strcmp(ins, PUSH_A) == 0 ? a : b;
	if (*src)
	{
		if (stack_push(dest, (*src)->data) == false)
			return (false);
		stack_pop(src);
	}
	return (true);
}

int	rotate(t_stack **a, t_stack **b, char *ins)
{
	t_stack *queueNode;

	if ((ft_strcmp(ins, ROT_A) == 0 || ft_strcmp(ins, ROT_BOTH) == 0) && *a)
	{
		queueNode = *a;
		while (queueNode->next)
			queueNode = queueNode->next;
		if ((queueNode->next = ft_memalloc(sizeof(t_stack))) == NULL)
			return (false);
		queueNode->next->data = (*a)->data;
		queueNode->next->next = NULL;
		stack_pop(a);
	}
	if ((ft_strcmp(ins, ROT_B) == 0 || ft_strcmp(ins, ROT_BOTH) == 0) && *b)
	{
		queueNode = *b;
		while (queueNode->next)
			queueNode = queueNode->next;
		if ((queueNode->next = ft_memalloc(sizeof(t_stack))) == NULL)
			return (false);
		queueNode->next->data = (*b)->data;
		queueNode->next->next = NULL;
		stack_pop(b);
	}
	return (true);
}

int	revrot(t_stack **a, t_stack **b, char *ins)
{
	t_stack *queueNode;

	if ((ft_strcmp(ins, REVROT_A) == 0 || ft_strcmp(ins, REVROT_BOTH) == 0)
	&& ((*a) && (*a)->next))
	{
		queueNode = *a;
		while (queueNode->next->next)
			queueNode = queueNode->next;
		if (stack_push(a, queueNode->next->data) == false)
			return (false);
		free(queueNode->next);
		queueNode->next = NULL;
	}
	if ((ft_strcmp(ins, REVROT_B) == 0 || ft_strcmp(ins, REVROT_BOTH) == 0)
	&& ((*b) && (*b)->next))
	{
		queueNode = *b;
		while (queueNode->next->next)
			queueNode = queueNode->next;
		if (stack_push(b, queueNode->next->data) == false)
			return (false);
		free(queueNode->next);
		queueNode->next = NULL;
	}
	return (true);
}

void	get_inst_func_array(t_inst_func **tab)
{
	(*tab)->ptrfunc = &swap;
	(*tab)->key = SWAP_A;
	(*tab + 1)->ptrfunc = &swap;
	(*tab + 1)->key = SWAP_B;
	(*tab + 2)->ptrfunc = &swap;
	(*tab + 2)->key = SWAP_BOTH;
	(*tab + 3)->ptrfunc = &push;
	(*tab + 3)->key = PUSH_A;
	(*tab + 4)->ptrfunc = &push;
	(*tab + 4)->key = PUSH_B;
	(*tab + 5)->ptrfunc = &rotate;
	(*tab + 5)->key = ROT_A;
	(*tab + 6)->ptrfunc = &rotate;
	(*tab + 6)->key = ROT_B;
	(*tab + 7)->ptrfunc = &rotate;
	(*tab + 7)->key = ROT_BOTH;
	(*tab + 8)->ptrfunc = &revrot;
	(*tab + 8)->key = REVROT_A;
	(*tab + 9)->ptrfunc = &revrot;
	(*tab + 9)->key = REVROT_B;
	(*tab + 10)->ptrfunc = &revrot;
	(*tab + 10)->key = REVROT_BOTH;
	(*tab + 11)->ptrfunc = NULL;
	(*tab + 11)->key = NULL;
}

int	exec_instructions(char *instructions, t_stack **a, t_stack **b, t_inst_func *tab)
{
	int i;

	i = 0;
	while (tab[i].key != NULL)
	{
		if (ft_strcmp(tab[i].key, instructions) == 0)
			return (tab[i].ptrfunc(a, b, instructions));
		i++;
	}
	return (false);
}

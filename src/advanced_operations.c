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

void	swap(t_stack *s1, t_stack *s2)
{
	int tmp;

	if (s1 && s1->next)
	{
		tmp = s1->data;
		s1->data = s1->next->data;
		s1->next->data = tmp;
	}
	if (s2 && s2->next)
	{
		tmp = s2->data;
		s2->data = s2->next->data;
		s2->next->data = tmp;
	}
}

int	push(t_stack **dest, t_stack **src)
{
	if (src && *src)
	{
		if (stack_push(dest, (*src)->data) == false)
			return (false);
		stack_pop(src);
	}
	return (true);
}

int	rotate(t_stack **s1, t_stack **s2)
{
	t_stack *queueNode;

	if (s1 && *s1 && (*s1)->next)
	{
		queueNode = *s1;
		while (queueNode->next)
			queueNode = queueNode->next;
		if ((queueNode->next = ft_memalloc(sizeof(t_stack))) == NULL)
			return (false);
		queueNode->next->data = (*s1)->data;
		queueNode->next->next = NULL;
		stack_pop(s1);
	}
	if (s2 && *s2 && (*s2)->next)
	{
		queueNode = *s2;
		while (queueNode->next)
			queueNode = queueNode->next;
		if ((queueNode->next = ft_memalloc(sizeof(t_stack))) == NULL)
			return (false);
		queueNode->next->data = (*s2)->data;
		queueNode->next->next = NULL;
		stack_pop(s2);
	}
	return (true);
}

int	revrot(t_stack **s1, t_stack **s2)
{
	t_stack *queueNode;

	if (s1 && *s1 && (*s1)->next)
	{
		queueNode = *s1;
		while (queueNode->next->next)
			queueNode = queueNode->next;
		if (stack_push(s1, queueNode->next->data) == false)
			return (false);
		free(queueNode->next);
		queueNode->next = NULL;
	}
	if (s2 && *s2 && (*s2)->next)
	{
		queueNode = *s2;
		while (queueNode->next->next)
			queueNode = queueNode->next;
		if (stack_push(s2, queueNode->next->data) == false)
			return (false);
		free(queueNode->next);
		queueNode->next = NULL;
	}
	return (true);
}

int	exec_instructions(char *command, t_stack **a, t_stack **b)
{
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
	else if (ft_strcmp(command, ROT_B) == 0)
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
	return (true);
}

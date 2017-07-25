/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:36:49 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:56:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_push(t_stack **s_top, int data)
{
	t_stack *newnode;

	if ((newnode = ft_memalloc(sizeof(t_stack))) == NULL)
		return (false);
	newnode->data = data;
	if (*s_top == NULL)
	{
		newnode->next = NULL;
	}
	else
	{
		newnode->next = *s_top;
	}
	*s_top = newnode;
	return (true);
}

void	stack_pop(t_stack **s_top)
{
	t_stack *tmp;

	if (*s_top != NULL)
	{
		tmp = *s_top;
		*s_top = tmp->next;
		free(tmp);
	}
}

int		ascending_check(t_stack *stack)
{
	int		data;
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		data = tmp->data;
		if ((tmp = tmp->next) != NULL)
		{
			if (data > tmp->data)
				return (false);
		}
	}
	return (true);
}

int		descending_check(t_stack *stack)
{
	int		data;
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		data = tmp->data;
		if ((tmp = tmp->next) != NULL)
		{
			if (data < tmp->data)
				return (false);
		}
	}
	return (true);
}

int 	stack_len(t_stack *s)
{
	int i;

	i = 0;
	while (s != NULL)
	{
		s = s->next;
		i++;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:36:49 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 15:22:53 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push(t_stack **s_top, int data)
{
	t_stack *newNode;

	if ((newNode = ft_memalloc(sizeof(t_stack))) == NULL)
		return (false);
	newNode->data = data;
	if (*s_top == NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *s_top;
	}
	*s_top = newNode;
	return (true);
}

void	stack_pop(t_stack **s_top)
{
	t_stack *tmp;

	if (*s_top)
	{
		tmp = *s_top;
		*s_top = tmp->next;
		free(tmp);
	}
}

int		check_stack_order(t_stack *a, t_stack *b)
{
	int data;
	t_stack *tmp;

	tmp = a;
	if (b)
		return (false);
	while (tmp)
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

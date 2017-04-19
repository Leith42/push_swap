/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:36:49 by aazri             #+#    #+#             */
/*   Updated: 2017/04/19 18:19:37 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Step 1: Create a newNode with given value.
    Step 2: Check whether stack is Empty (top == NULL)
    Step 3: If it is Empty, then set newNode → next = NULL.
    Step 4: If it is Not Empty, then set newNode → next = top.
    Step 5: Finally, set top = newNode.
*/

void	stack_push(t_stack **s, int data)
{
	t_stack *newNode;

	if ((newNode = ft_memalloc(sizeof(t_stack))) == NULL)
		handle_error(MEM_ALLOC);
	newNode->data = data;
	if (*s == NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *s;
	}
	*s = newNode;
}
/*
void	stack_pop(t_stack *s)
{
	if (s->size > 0)
	{
		s->size--;
	}
	else
	{
		handle_error(STACK_IS_EMPTY);
	}
}*/

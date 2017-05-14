/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:23:43 by aazri             #+#    #+#             */
/*   Updated: 2017/05/03 14:00:36 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	stack_len(t_stack **s)
{
	int i;
	t_stack *tmpNode;

	i = 1;
	tmpNode = *s;
	while (tmpNode != NULL)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	return (i);
}

void	new_root(t_list **inst, char *str)
{
	t_list *tmp;

	tmp = *inst;
	if (*inst == NULL)
	{
		*inst = ft_lstnew(str, ft_strlen(str));
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(str, ft_strlen(str));
	}
}

int	get_min_pos(t_stack **s)
{
	t_stack *tmpNode;
	int min;
	int i;
	int pos;

	pos = 0;
	if (*s)
	{
		i = 0;
		tmpNode = *s;
		min = tmpNode->data;
		while (tmpNode != NULL)
		{
			if (tmpNode->data < min)
			{
				min = tmpNode->data;
				pos = i;
			}
			tmpNode = tmpNode->next;
			i++;
		}
	}
	return (pos);
}

int push_swap(t_stack **a, t_stack **b, t_list **inst, int a_len)
{
	int min;

	while ((*a))
	{
		min = get_min_pos(a);
		if ((a_len > 1) && (min > (a_len / 2)))
		{
			while (min++ < a_len)
			{
				if (exec_instructions(REVROT_A, a, b) == false)
					return (false);
				new_root(inst, REVROT_A);
			}
		}
		else
		{
			while (min-- > 0)
			{
				if (exec_instructions(ROT_A, a, b) == false)
					return (false);
				new_root(inst, ROT_A);
			}
		}
		/*if (*b == NULL && check_the_order(*a) == true)
			return (true);*/
		if (exec_instructions(PUSH_B, a, b) == false)
			return (false);
		new_root(inst, PUSH_B);
	}
	while (*b)
	{
		if (exec_instructions(PUSH_A, a, b) == false)
			return (false);
		new_root(inst, PUSH_A);
	}
	return (true);
}

int main(int argc, char const *argv[])
{
	t_stack *a;
	t_stack *b;
	t_list *instructions;
	int a_len;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &a, NULL) == false))
			handle_error(&a, &b, NULL);
		a_len = stack_len(&a);
		/*ft_printf("%d\n", a_len);
		if ((push_swap(&a, &b, &instructions, a_len) == false))
			handle_error(&a, &b, NULL);
		while (instructions)
		{

			ft_printf("%s ", instructions->content);
			instructions = instructions->next;
		}*/
		stack_print(a, b);
		//clear(&a, &b, NULL);
	}
	else
		ft_printf("Usage: ./push_swap 1 2 3 4...\n");
	return 0;
}

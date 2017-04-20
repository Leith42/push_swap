/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:33:06 by aazri             #+#    #+#             */
/*   Updated: 2017/04/19 20:54:02 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	stack_print(t_stack *s)
{
	t_stack *tmp;

	tmp = s;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	check_stack_order(t_stack *s)
{
	int data;
	t_stack *tmp;

	tmp = s;
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

int	main(int argc, char const *argv[])
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		parsing_args(argv, argc, &a);
	//	get_instructions();
		stack_print(a);
		if (check_stack_order(a) == true)
			ft_printf("\nOK\n");
		else
			ft_printf("\nKO\n");
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:23:43 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:40:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_list *i)
{
	while (i != NULL)
	{
		ft_printf("%s\n", i->content);
		i = i->next;
	}
}

void	stock_instruction(t_list **inst, char *str)
{
	t_list *tmp;

	tmp = *inst;
	if (*inst == NULL)
	{
		*inst = ft_lstnew(str, ft_strlen(str) + 1);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(str, ft_strlen(str) + 1);
	}
}

int		main(int argc, char const *argv[])
{
	t_stack *a;
	t_stack *b;
	t_list	*instructions;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc > 1)
	{
		if (args_parse(argv, argc, &a, NULL) == false
		|| push_swap(&a, &b, &instructions) == false)
		{
			handle_error(a, b, instructions);
		}
		free_stack(a, b);
		print_instructions(instructions);
		ft_lstdel(&instructions, &clear_list);
	}
	else
		ft_putendl("Usage: ./push_swap 1 2 3 4...");
	return (EXIT_SUCCESS);
}

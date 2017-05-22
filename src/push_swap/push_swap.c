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

#include "push_swap.h"

void	print_instructions(t_list *i)
{
	t_list *tmp;

	while (i)
	{
		ft_printf("%s\n", i->content);
		tmp = i;
		i = i->next;
		free(tmp);
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

int main(int argc, char const *argv[])
{
	t_stack *a;
	t_stack *b;
	t_list *instructions;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc > 1)
	{
		if (args_parse(argv, argc, &a, NULL) == false || push_swap(&a, &b, &instructions) == false)
		{
			ft_lstdel(&instructions, &clear_list);
			handle_error(a, b);
		}
		print_instructions(instructions);
		free_stack(a, b);
	}
	else
		ft_putendl("Usage: ./push_swap 1 2 3 4...");
	return (EXIT_SUCCESS);
}
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
		while (instructions)
		{
			ft_printf("%s\n", instructions->content);
			instructions = instructions->next;
		}
		free_stack(a, b);
		if (instructions)
			free(instructions);
	}
	else
		ft_printf("Usage: ./push_swap -2 -1 0 1 2...\n");
	return (EXIT_SUCCESS);
}
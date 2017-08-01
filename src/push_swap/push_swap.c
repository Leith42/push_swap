/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:23:43 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 15:27:36 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_usage(void)
{
	ft_putendl("usage: ./push_swap 1 2 3 4... [-qsort] or [-ssort]");
	ft_putendl("[-qsort]: Forces the use of a quick sort algorithm.");
	ft_putendl("[-ssort]: Forces the use of a selection sort algorithm.");
	ft_putendl("By default the program will choose the most optimized algorithm"
				"according to the number of integers.");
}

void	print_instructions(t_list *i)
{
	while (i != NULL)
	{
		ft_putendl(i->content);
		i = i->next;
	}
}

int		push_swap(t_stack **a, t_stack **b, t_list **inst, t_options *options)
{
	t_qsort data;

	if (ascending_check(*a) == true)
	{
		return (true);
	}
	else if ((options->selection_sort == true) ||
			(options->quick_sort == false && stack_len(*a) <= 13))
	{
		return (ps_ssort(a, b, inst));
	}
	else
	{
		data.len = stack_len(*a);
		ps_qsort(a, b, inst, data);
		return (true);
	}
}

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_list		*instructions;
	t_options	*options;

	a = NULL;
	b = NULL;
	instructions = NULL;
	options = NULL;
	if (argc > 1)
	{
		if (args_parse(argv, argc, &a, &options) == false ||
			push_swap(&a, &b, &instructions, options) == false ||
			op_reducer(instructions) == false)
		{
			handle_error(a, b, instructions, options);
		}
		print_instructions(instructions);
		freedom(a, b, instructions, options);
	}
	else
	{
		display_usage();
	}
	return (EXIT_SUCCESS);
}

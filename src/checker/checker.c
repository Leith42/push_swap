/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:33:06 by aazri             #+#    #+#             */
/*   Updated: 2017/06/19 16:45:58 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_usage(void)
{
	ft_putendl("usage: ./checker 1 2 3 4... [-i] [-v]");
	ft_putendl("[-i]: prints the number of instructions executed.");
	ft_putendl("[-v]: updates the display of the stacks.");
}

int		main(int argc, char *argv[])
{
	int			inst_nb;
	t_stack		*a;
	t_stack		*b;
	t_options	*o;

	a = NULL;
	b = NULL;
	o = NULL;
	inst_nb = 0;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &a, &o) == false)
		|| (instructions_parsing(&a, &b, o, &inst_nb) == ERROR))
		{
			handle_error(a, b, NULL);
		}
		print_result(a, b, o, inst_nb);
		free_stack(a, b);
		free(o);
	}
	else
	{
		display_usage();
	}
	return (EXIT_SUCCESS);
}

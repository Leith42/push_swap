/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:33:06 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 18:01:27 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	int		inst_nb;
	t_stack	*a;
	t_stack	*b;
	t_options *o;

	a = NULL;
	b = NULL;
	o = NULL;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &a, &o) == false)
		|| (instructions_parsing(&a, &b, o, &inst_nb) == ERROR))
		{
			handle_error(a, b);
		}
		print_result(a, b, o, inst_nb);
		free_stack(a, b);
		free(o);
	}
	else
	{
		ft_putendl("usage: ./checker 1 2 3 4... [-i] [-v] [-s]");
		ft_putendl("[-i]: displays the number of instructions executed.");
		ft_putendl("[-v]: displays the current state of the stacks.");
		ft_putendl("[-s]: only displays the KO or OK status of the stack.");
	}
	return (EXIT_SUCCESS);
}

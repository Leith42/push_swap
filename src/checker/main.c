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

int	args_parse(const char **argv, int argc, t_stack **s, t_options **opt)
{
	if (opt)
	{
		if ((*opt = ft_memalloc(sizeof(t_options))) == NULL)
			return (false);
	}
	if (browse_arguments(argv, opt) == false)
		return (false);
	if (length_checker(argv) == false)
		return (false);
	if (duplicate_checker(argv) == false)
		return (false);
	if (stack_init(argc, argv, s) == false)
		return (false);
	return (true);
}


int	main(int argc, char const *argv[])
{
	int		inst_nb;
	t_stack	*a;
	t_stack	*b;
	t_options *o;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &a, &o) == false)
		|| (instructions_parse(&a, &b, &o, &inst_nb) == ERROR))
		{
			handle_error(&a, &b, &o);
		}
		if (inst_nb > 0)
			stack_print(a, b);
		ft_printf("\nStack status : ");
		ft_putendl(check_stack_order(a, b) ? "OK" : "KO");
		ft_printf("Instructions executed : %d\n", inst_nb);
		clear(&a, &b, &o);
	}
	else
		ft_putendl("Usage: ./checker 1 2 3 4... [-c] [-v]");
	return (EXIT_SUCCESS);
}

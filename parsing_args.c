/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:43:38 by aazri             #+#    #+#             */
/*   Updated: 2017/04/20 12:52:26 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing_args(const char **argv, int argc, t_stack **a)
{
	digit_checker(argv);
	length_checker(argv);
	stack_init(argc, argv, a);
}

void	digit_checker(const char **argv)
{
	unsigned int i;
	unsigned int j;
	unsigned int minus;

	i = 1;
	while (argv[i])
	{
		j = 0;
		minus = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == FALSE)
			{
				minus++;
				if (argv[i][j] != '-' || argv[i][j + 1] == '\0' || minus > 1)
					handle_error(ONE_ARG_IS_NOT_DIGIT);
			}
			j++;
		}
		i++;
	}
}

void	length_checker(const char *argv[])
{
	unsigned int i;
	intmax_t current;

	i = 0;
	while (argv[i])
	{
		if ((current = ft_atol(argv[i], BASE_DECIMAL)) > INT_MAX)
		{
			handle_error(ONE_ARG_IS_TOO_BIG);
		}
		i++;
	}
}

void	stack_init(int argc, char const *argv[], t_stack **a)
{
	int i;

	i = argc;
	while (--i)
	{
		stack_push(a, ft_atol(argv[i], BASE_DECIMAL));
	}
}

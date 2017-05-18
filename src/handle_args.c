/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:43:38 by aazri             #+#    #+#             */
/*   Updated: 2017/05/03 14:02:44 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	browse_arguments(const char **argv, t_options *opt)
{
	unsigned int i;

	i = 1;
	while (argv[i])
	{
		if (arg_validity_checker(argv[i], opt) == false)
			return (false);
		i++;
	}
	return (true);
}

int	arg_validity_checker(const char *arg, t_options *opt)
{
	unsigned int i;

	i = 0;
	if ((arg[i] == '-' && ft_isdigit(arg[i + 1]) == true) ||
	(ft_isdigit(arg[i]) == true))
	{
		while (arg[++i])
		{
			if (ft_isdigit(arg[i]) == false)
				return (false);
		}
	}
	else if (opt && arg[i] == '-' && arg[i + 1] == 'v' && arg[i + 2] == '\0')
		opt->screen_refresh = 1;
	else
		return (false);
	return (true);
}

int	length_checker(const char *argv[])
{
	unsigned int i;
	intmax_t current;

	i = 1;
	while (argv[i])
	{
		if ((current = ft_atol(argv[i], BASE_DECIMAL)) > INT_MAX)
			return (false);
		i++;
	}
	return (true);
}

int	duplicate_checker(const char *argv[])
{
	unsigned int i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] && argv[i + 1])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) == 0)
				return (false);
		}
		i++;
	}
	return (true);
}

int	stack_init(int argc, char const *argv[], t_stack **s)
{
	int i;

	i = argc;
	while (--i)
	{
		if (ft_isdigit(argv[i][0]) || ft_isdigit(argv[i][1]))
		{
			if ((stack_push(s, ft_atol(argv[i], BASE_DECIMAL))) == false)
				return (false);
		}
	}
	return (true);
}

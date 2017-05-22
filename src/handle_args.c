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

int	browse_arguments(const char **argv, t_options **opt)
{
	int i;
	bool digit;

	i = 1;
	digit = false;
	while (argv[i])
	{
		if (arg_validity_checker(argv[i], opt) == false)
			return (false);
		if (digit == false)
		{
			if ((argv[i][0] == '-' && ft_isdigit(argv[i][1]) == true)
				|| (ft_isdigit(argv[i][0]) == true))
			{
				digit = true;
			}
		}
		i++;
	}
	return (digit);
}

int	arg_validity_checker(const char *arg, t_options **opt)
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
<<<<<<< HEAD
		(*opt)->screen_refresh = (*opt)->silence == true ? false : true;
	else if (opt && arg[i] == '-' && arg[i + 1] == 'i' && arg[i + 2] == '\0')
		(*opt)->display_commands = (*opt)->silence == true ? false : true;
	else if (opt && arg[i] == '-' && arg[i + 1] == 's' && arg[i + 2] == '\0')
	{
		(*opt)->silence = true;
		(*opt)->screen_refresh = false;
		(*opt)->display_commands = false;
	}
=======
		(*opt)->screen_refresh = true;
	else if (opt && arg[i] == '-' && arg[i + 1] == 'i' && arg[i + 2] == '\0')
		(*opt)->display_commands = true;
>>>>>>> master
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
	int i;
	int c;

	i = 1;
	while (argv[i])
	{
		c = i + 1;
		while (argv[c])
		{
			if (ft_strcmp(argv[i], argv[c]) == 0)
				return (false);
			c++;
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

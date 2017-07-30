/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:43:38 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:54:56 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	browse_arguments(char **array, t_options **opt)
{
	int		i;
	bool	digit;

	i = 0;
	digit = false;
	while (array[i])
	{
		if (arg_validity_checker(array[i], opt) == false)
		{
			return (false);
		}
		if (digit == false)
		{
			if ((array[i][0] == '-' && ft_isdigit(array[i][1]) == true)
				|| (ft_isdigit(array[i][0]) == true))
			{
				digit = true;
			}
		}
		i++;
	}
	return (digit);
}

int	arg_validity_checker(char *arg, t_options **opt)
{
	int i;

	i = arg[0] == '-' || arg[0] == '+' ? 1 : 0;
	if (ft_isdigit(arg[i]) == true)
	{
		if ((arg[i] == '0' && arg[i + 1] != '\0') ||
			(arg[0] == '-' && arg[1] == '0'))
				return (false);
		while (arg[++i] != '\0')
		{
			if (ft_isdigit(arg[i]) == false)
				return (false);
		}
	}
	else if (opt && ft_strcmp(arg, "-v") == 0)
		(*opt)->stack_refresh = true;
	else if (opt && ft_strcmp(arg, "-i") == 0)
		(*opt)->display_commands = true;
	else if (opt && ft_strcmp(arg, "-c") == 0)
		(*opt)->clear_screen = true;
	else if (opt && ft_strcmp(arg, "-ssort") == 0)
		(*opt)->selection_sort = true;
	else if (opt && ft_strcmp(arg, "-qsort") == 0)
		(*opt)->quick_sort = true;
	else
		return (false);
	return ((*opt)->quick_sort == true && (*opt)->selection_sort == true ? false : true);
}

int	length_checker(char *argv[])
{
	int	i;
	intmax_t		arg;

	i = 0;
	while (argv[i])
	{
		arg = ft_atol(argv[i], BASE_DECIMAL);
		if (arg > INT_MAX || arg < INT_MIN)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

int	duplicate_checker(char *argv[])
{
	int i;
	int c;

	i = 0;
	while (argv[i])
	{
		c = i + 1;
		while (argv[c])
		{
			if (ft_strcmp(argv[i], argv[c]) == 0)
			{
				return (false);
			}
			c++;
		}
		i++;
	}
	return (true);
}

int	stack_init(char *argv[], t_stack **s)
{
	int i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	while (i-- != 0)
	{
		if (ft_isdigit(argv[i][0]) || ft_isdigit(argv[i][1]))
		{
			if ((stack_push(s, ft_atoi(argv[i])) == false))
			{
				return (false);
			}
		}
	}
	return (true);
}

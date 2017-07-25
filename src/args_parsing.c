/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:30:17 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:34:58 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(char **arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static char	**get_args_array(char **argv, int argc)
{
	char **array;
	int i;

	if (argc == 2)
	{
		return (ft_strsplit(argv[1], ' '));
	}
	else
	{
		if ((array = ft_memalloc(sizeof(array) * argc)) == NULL)
		{
			return (NULL);
		}
		i = 0;
		while (argv[i + 1])
		{
			if ((array[i] = ft_strdup(argv[i + 1])) == NULL)
			{
				return (NULL);
			}
			i++;
		}
		array[i] = NULL;
		return (array);
	}
}

int		args_parse(char **argv, int argc, t_stack **s, t_options **opt)
{
	char **array;

	if ((*opt = ft_memalloc(sizeof(t_options))) == NULL ||
		(array = get_args_array(argv, argc)) == NULL ||
		(browse_arguments(array, opt)) == false ||
		(length_checker(array)) == false ||
		(duplicate_checker(array)) == false ||
		(stack_init(array, s) == false))
	{
		free_array(array);
		return (false);
	}
	free_array(array);
	return (true);
}

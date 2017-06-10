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

int	args_parse(const char **argv, int argc, t_stack **s, t_options **opt)
{
	if (opt != NULL)
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

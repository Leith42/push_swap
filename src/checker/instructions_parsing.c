/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:28:38 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:52:10 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	instructions_parsing(t_stack **a, t_stack **b, t_options *opt, int *inst_nb)
{
	int		gnl;
	char	*command;

	*inst_nb = 0;
	if (opt->silence == false)
	{
		stack_print(*a, *b);
		ft_printf("Enter instructions :\n");
	}
	while ((gnl = get_next_line(0, &command)))
	{
		if (exec_instructions(command, a, b) == false)
			return (ERROR);
		(*inst_nb)++;
		if (opt->screen_refresh == true)
			stack_print(*a, *b);
		if (opt->display_commands == true)
			ft_printf("Instructions executed :\t%d\n\n", *inst_nb);
		free(command);
	}
	return (gnl);
}

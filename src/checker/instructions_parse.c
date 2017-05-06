/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:28:38 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 13:21:33 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	instructions_parse(t_stack **a, t_stack **b, t_options **opt, int *inst_nb)
{
	int gnl;
	char *instructions;
	t_inst_func *tab;

	*inst_nb = 0;
	if ((tab = ft_memalloc(sizeof(t_inst_func) * 12)) == NULL)
		return (false);
	get_inst_func_array(&tab);
	stack_print(*a, *b);
	ft_printf("Enter instructions :\n");
	while ((gnl = get_next_line(0, &instructions)))
	{
		if (exec_instructions(instructions, a, b, tab) == false)
			return (ERROR);
		(*inst_nb)++;
		if ((*opt)->screen_refresh)
			stack_print(*a, *b);
		free(instructions);
	}
	free(tab);
	return (gnl);
}

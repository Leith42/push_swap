/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:21:33 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:55:13 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_stack *a, t_stack *b, t_options *o, int inst_nb)
{
	if (inst_nb > 0 && o->silence == false)
	{
		if (o->screen_refresh == true)
			ft_putstr("\033c");
		stack_print(a, b);
		if (o->display_commands == true)
			ft_printf("Instructions executed :\t{GREEN}%d{EOC}\n", inst_nb);
	}
	ft_putendl(b == NULL && ascending_check(a) ? "\nOK" : "\nKO");
}

void	stack_print(t_stack *a, t_stack *b)
{
	ft_putendl("-------------------------");
	ft_putendl(" Stack A         Stack B ");
	ft_putendl("---------   |   ---------");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %-15d", a->data);
			a = a->next;
		}
		else
			ft_printf("%16c", ' ');
		if (b)
		{
			ft_printf(" %d", b->data);
			b = b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("-------------------------\n");
}

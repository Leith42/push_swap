/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:21:33 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 13:38:18 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_stack *a, t_stack *b, t_options *o, int inst_nb)
{
	if (inst_nb > 0)
	{
		if (o->clear_screen == true)
		{
			ft_cls();
		}
		if (o->stack_refresh == true)
		{
			stack_print(a, b);
		}
		if (o->display_commands == true)
		{
			ft_printf("Instructions executed :\t{GREEN}%d{EOC}\n", inst_nb);
		}
	}
	ft_printf(b == NULL &&
		ascending_check(a) ? "\n{GREEN}OK{EOC}\n" : "\n{RED}KO{EOC}\n");
}

void	stack_print(t_stack *a, t_stack *b)
{
	ft_printf("{GREEN}-------------------------{EOC}\n");
	ft_printf(" {RED}Stack A         Stack B{EOC} \n");
	ft_printf("{GREEN}---------   |   ---------{EOC}\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf(" %-15d", a->data);
			a = a->next;
		}
		else
		{
			ft_printf("%16c", ' ');
		}
		if (b)
		{
			ft_printf(" %d", b->data);
			b = b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("{GREEN}-------------------------{EOC}\n");
}

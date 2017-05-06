/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:21:33 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 15:21:40 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_print(t_stack *a, t_stack *b)
{
	ft_printf("-------------------------\n");
	ft_printf(" Stack A         Stack B \n");
	ft_printf("---------   |   ---------\n");
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

			ft_printf("%d", b->data);
			b = b->next;
		}
		ft_putchar('\n');
	}
	ft_printf("-------------------------\n");
}

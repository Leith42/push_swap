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

void	print_result(t_stack *a, t_stack *b, int inst_nb)
{
<<<<<<< HEAD
	if (inst_nb > 0 && o->silence == false)
=======
	if (inst_nb > 0)
>>>>>>> master
	{
		stack_print(a, b);
		ft_putchar('\n');
	}
	ft_putendl(b == NULL && ascending_check(a) ? "OK" : "KO");
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

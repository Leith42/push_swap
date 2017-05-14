/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:25:14 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 15:06:05 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_stack **a, t_stack **b, t_options **opt)
{
	t_stack	*tmp_s;

	while (a && *a)
	{
		tmp_s = (*a)->next;
		free(*a);
		*a = tmp_s;
	}
	while (b && *b)
	{
		tmp_s = (*b)->next;
		free(*b);
		*b = tmp_s;
	}
	if (opt && *opt)
		free(*opt);
}

void	clear_list(void *data, size_t n)
{
	if (data)
		free(data);
	n = 0;
}

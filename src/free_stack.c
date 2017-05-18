/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:25:14 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 15:06:05 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a, t_stack *b)
{
	t_stack	*tmp_s;

	while (a)
	{
		tmp_s = a->next;
		free(a);
		a = tmp_s;
	}
	while (b)
	{
		tmp_s = b->next;
		free(b);
		b = tmp_s;
	}
}

void	clear_list(void *data, size_t n)
{
	if (data)
		free(data);
	n = 0;
}

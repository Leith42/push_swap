/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:25:14 by aazri             #+#    #+#             */
/*   Updated: 2017/05/24 16:30:22 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freedom(t_stack *a, t_stack *b, t_list *i, t_options *o)
{
	t_stack	*tmp_s;

	while (a != NULL)
	{
		tmp_s = a->next;
		free(a);
		a = tmp_s;
	}
	while (b != NULL)
	{
		tmp_s = b->next;
		free(b);
		b = tmp_s;
	}
	if (i != NULL)
	{
		ft_lstdel(&i, &clear_list);
	}
	if (o != NULL)
	{
		free(o);
	}
}

void	clear_list(void *data, size_t n)
{
	if (data != NULL)
	{
		free(data);
	}
	(void)n;
}

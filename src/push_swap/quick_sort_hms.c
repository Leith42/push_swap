/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_hms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 15:21:12 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 15:22:47 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		how_many_sorts(t_stack *a, int pivot, int len)
{
	int i;

	i = 0;
	while (len)
	{
		if (a->data < pivot)
		{
			i++;
		}
		a = a->next;
		len--;
	}
	return (i);
}

int		rev_how_many_sort(t_stack *a, int pivot, int len)
{
	int i;

	i = 0;
	while (len)
	{
		if (a->data > pivot)
		{
			i++;
		}
		a = a->next;
		len--;
	}
	return (i);
}

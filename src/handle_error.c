/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:47:01 by aazri             #+#    #+#             */
/*   Updated: 2017/05/02 15:00:08 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(t_stack **a, t_stack **b, t_options **o)
{
	ft_putstr_fd("Error\n", 2);
	clear (a, b, o);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:47:01 by aazri             #+#    #+#             */
/*   Updated: 2017/04/19 16:50:00 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(int error)
{
	if (error == ONE_ARG_IS_TOO_BIG)
	{
		ft_putstr_fd("Error: one argument is too big.\n", 2);
	}
	else if (error == ONE_ARG_IS_NOT_DIGIT)
	{
		ft_putstr_fd("Error: one argument is not digit.\n", 2);
	}
	else if (error == STACK_IS_EMPTY)
	{
		ft_putstr_fd("Error: stack is empty.\n", 2);
	}
	else if (error == MEM_ALLOC)
	{
		ft_putstr_fd("Error: memory allocation failed.\n", 2);
	}
	exit(EXIT_FAILURE);
}

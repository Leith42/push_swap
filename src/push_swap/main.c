/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:23:43 by aazri             #+#    #+#             */
/*   Updated: 2017/05/03 14:00:36 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const *argv[])
{
	t_stack *s;

	s = NULL;
	if (argc > 1)
	{
		if ((args_parse(argv, argc, &s, NULL) == false))
			handle_error(&s, NULL, NULL);
		//stack_print(s, NULL);
	}
	else
		ft_putendl("Usage: ./push_swap 1 2 3 4...");
	return 0;
}

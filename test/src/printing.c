/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 23:47:08 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/02 04:36:07 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		init_stacks(t_stack *a, t_stack *b, int ac, char **ar)
{
	int		i;
	int		j;
	char	**argv;
	int		argc;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		argv = ft_strsplit(ar[1], ' ');
		argc = (int)ft_count_words(ar[1], ' ');
		ac = argc;
		stack_new(a, argc);
		stack_new(b, argc);
	}else
	{
		argv = ar + 1;
		argc = ac - 1;
		ac = argc;
		stack_new(a, argc);
		stack_new(b, argc);
	}
	*(a->elems + argc - 1) = 0;
	*(b->elems + argc - 1) = 0;
	while (argc > 0)
	{
		//char c = argc + '0';
		//write(1, &c, 2);
		//printf("%s::::::", argv[argc-1]);
		while (argv[argc - 1][j])
		{
			if (!ft_isdigit(argv[argc - 1][j]))
			{
				write(1, "Error", 5);
				return (0);
			}
			j++;
		}
		stack_push(a, ft_atoi(argv[argc - 1]));		
		b->elems[i] = 0;
		i++;
		argc--;
	}
	return (ac);
}

void	print_stacks(t_stack *a, t_stack *b, int i, char **instr)
{
	while (i >= 0)
	{
		if (i == (a->log_len - 1) || i == (b->log_len -1 ))
			printf(">");
		printf("%d\t%s\t|\n", *(a->elems + i), *(b->elems + i) == 0 ? " " : ft_itoa(b->elems[i]));
		i--;
	}
	printf("-\t-  |\na\tb  |\n");
	i=0;
	while (instr[i])
	{
		printf("%s\n", instr[i]);
		i++;
	}
}

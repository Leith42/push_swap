/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 12:58:17 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/02 04:29:55 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.
• In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.
*/
#include "checker.h"
#include "push_swap.h"

/* wait and read instructions , each instruction will be followed by ’\n’.-done*/
int		read_instr(char **instr)
{
	int i;
	int nbytes;
	char *line;

	i = 0;
	nbytes = 0;
	line = (char *)malloc(sizeof(char) * 6);
	
	while ((nbytes = get_next_line(0, &line)) && i < 20 && *line != '1')
	{
		instr[i] = ft_strdup(line);
		i++;
	}
	if (i == 20)
	{
		write(1, "Too many instructions\n", 22);
		ft_memdel((void **)&line);
		return(-3);
	}
	//instr[i] = ft_strdup("1");
	//write(1, "ass",3);
	ft_memdel((void **)&line);
	return (nbytes);
}

/** checker execute instructions e stack received as an argument.*/ 
void	apply_instr(t_stack *a, t_stack *b, char **instr)
{
	int i;

	i = 0;
	while (instr[i])
	{
		if (ft_strcmp(instr[i], "sa") == 0)
			swap(a);
		else if (ft_strcmp(instr[i], "sb") == 0)
			swap(b);
		else if (ft_strcmp(instr[i], "ss") == 0)
		{	swap(a);	swap(b);	}
		else if (ft_strcmp(instr[i], "pa") == 0)
			stack_push_on(a, b);
		else if (ft_strcmp(instr[i], "pb") == 0)
			stack_push_on(b, a);
		else if (ft_strcmp(instr[i], "ra") == 0)
			shift_up(a);
		else if (ft_strcmp(instr[i], "rb") == 0)
			shift_up(b);
		else if (ft_strcmp(instr[i], "rr") == 0)
		{	shift_up(a);	shift_up(b);	}
		else if (ft_strcmp(instr[i], "rra") == 0)
			shift_down(a);
		else if (ft_strcmp(instr[i], "rrb") == 0)
			shift_down(b);
		else if (ft_strcmp(instr[i], "rrr") == 0)
		{	shift_down(a);	shift_down(b);	}
		i++;
	}
}
/*
• argument is a stack of integers, first at the top of stack. --done
* If no argument is given checker stops and displays nothing. --done*/
int		main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;
	char **instr;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	instr = (char **)malloc(sizeof(char *) * 20);
	//char c = i + '0';
	//write(1, &c, 3);
	if (argc <= 1)
		return (0);
	else if (!(i = init_stacks(a, b, argc, argv)))
			return (0);		
	//ft_putnbr(i);
	if(read_instr(instr) != -3) /// need to change -3
	{
		//write(1, "woow", 4);
		apply_instr(a, b, instr);
		print_stacks(a, b, i, instr);
	}
	//printf("**%s**\n", ft_itoa(-50));
	//printf("%lu:%lu  %lu:%lu" ,sizeof(t_stack),sizeof(a),sizeof(char*),sizeof(instr) );
	free(a->elems);
	free(b->elems);
	ft_memdel((void **)instr);
	free(instr);
	return (0);
}

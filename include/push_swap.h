/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:21:01 by aazri             #+#    #+#             */
/*   Updated: 2017/05/03 14:02:20 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_BOTH "ss"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROT_A "ra"
# define ROT_B "rb"
# define ROT_BOTH "rr"
# define REVROT_A "rra"
# define REVROT_B "rrb"
# define REVROT_BOTH "rrr"

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_options
{
	bool		screen_refresh;
}				t_options;

typedef struct	s_inst_func
{
	int			(*ptrfunc)(t_stack **, t_stack **, char *);
	char		*key;
}				t_inst_func;

/*
	UTILS
*/
int		stack_push(t_stack **s_top, int data);
void	stack_pop(t_stack **s_top);
int		handle_error(t_stack **a, t_stack **b, t_options **opt);
void	clear(t_stack **a, t_stack **b, t_options **opt);
/*
	CHECKER
*/
int		check_stack_order(t_stack *a, t_stack *b);
void	get_inst_func_array(t_inst_func **tab);
void	stack_print(t_stack *a, t_stack *b);
long	ft_atol(const char *str, unsigned int base);
void	clear_list(void *data, size_t n);
int		args_parse(const char *argv[], int argc, t_stack **a, t_options **opt);
int		browse_arguments(const char *argv[], t_options **opt);
int		arg_validity_checker(const char *arg, t_options **opt);
int		length_checker(const char *argv[]);
int		duplicate_checker(const char *argv[]);
int		stack_init(int argc, char const *argv[], t_stack **a);
int		instructions_parsing(t_stack **a, t_stack **b, t_options **opt, int *inst_nb);
int		exec_instructions(char *command, t_stack **a, t_stack **b);
/*
	PUSH_SWAP
*/


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:21:01 by aazri             #+#    #+#             */
/*   Updated: 2017/06/09 14:41:57 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "struct.h"
# include <limits.h>

# define SWAP_A			"sa"
# define SWAP_B			"sb"
# define SWAP_BOTH		"ss"
# define PUSH_A			"pa"
# define PUSH_B			"pb"
# define ROT_A			"ra"
# define ROT_B			"rb"
# define ROT_BOTH		"rr"
# define REVROT_A		"rra"
# define REVROT_B		"rrb"
# define REVROT_BOTH	"rrr"

/*
**	OPERATIONS
*/

int		stack_push(t_stack **s_top, int data);
void	stack_pop(t_stack **s_top);
void	swap(t_stack *s1, t_stack *s2);
int		push(t_stack **dest, t_stack **src);
int		rotate(t_stack **s1, t_stack **s2);
int		revrot(t_stack **s1, t_stack **s2);
int		push_all_in_a(t_stack **a, t_stack **b, t_list **inst);

/*
**	ALGORITHM
*/

int		push_swap(t_stack **a, t_stack **b, t_list **inst);
int		ascending_check(t_stack *stack);
int		descending_check(t_stack *stack);

/*
**	PARSING
*/

int		instructions_parsing(t_stack **a, t_stack **b, t_options *o, int *i_nb);
int		args_parse(const char *argv[], int argc, t_stack **a, t_options **opt);
int		arg_validity_checker(const char *arg, t_options **opt);
int		duplicate_checker(const char *argv[]);
int		exec_instructions(char *command, t_stack **a, t_stack **b);
int		stack_init(int argc, char const *argv[], t_stack **a);
int		browse_arguments(const char *argv[], t_options **opt);
int		length_checker(const char *argv[]);
void	stock_instruction(t_list **inst, char *str);
int		stack_len(t_stack **s);
int		get_min(t_stack *s);

/*
**	UTILS
*/

void	handle_error(t_stack *a, t_stack *b);
void	free_stack(t_stack *a, t_stack *b);
void	clear_list(void *data, size_t n);
void	stack_print(t_stack *a, t_stack *b);
void	print_result(t_stack *a, t_stack *b, t_options *o, int inst_nb);

#endif

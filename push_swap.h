/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:21:01 by aazri             #+#    #+#             */
/*   Updated: 2017/04/19 18:21:27 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

# define STACK_MAX 100

typedef struct	s_stack
{
	int			data;
	void		*next;
}				t_stack;

enum {
	ONE_ARG_IS_TOO_BIG,
	ONE_ARG_IS_NOT_DIGIT,
	STACK_IS_FULL,
	STACK_IS_EMPTY,
	MEM_ALLOC
};

long	ft_atol(const char *str, unsigned int base);

void	stack_push(t_stack **s, int data);
void	stack_pop(t_stack *s);

int		handle_error(int error);

void	parsing_args(const char *argv[], int argc, t_stack **a);
void	digit_checker(const char *argv[]);
void	length_checker(const char *argv[]);
void	stack_init(int argc, char const *argv[], t_stack **a);

#endif

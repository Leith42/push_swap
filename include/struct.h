/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:40:32 by aazri             #+#    #+#             */
/*   Updated: 2017/06/09 14:41:48 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "push_swap.h"

typedef struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_options
{
	bool	screen_refresh;
	bool	display_commands;
	bool	silence;
}				t_options;

typedef struct	s_inst_func
{
	int		(*ptrfunc)(t_stack **, t_stack **, char *);
	char	*key;
}				t_inst_func;
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reducer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazri <aazri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 14:48:23 by aazri             #+#    #+#             */
/*   Updated: 2017/07/31 14:56:18 by aazri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	modify_prev_node(t_list *first_node, t_list *op, t_list *new)
{
	while (first_node->next != op)
	{
		first_node = first_node->next;
	}
	first_node->next = new;
}

static int	shorten_ops(t_list *op, int *b)
{
	t_list	*tmp;
	char	*shortcut;

	while (op)
	{
		if (op->next != NULL && (shortcut = do_we_cut(op)) != NULL)
		{
			free(op->content);
			if ((op->content = ft_strdup(shortcut)) == NULL)
			{
				return (false);
			}
			tmp = op->next;
			op->next = op->next->next;
			free(tmp->content);
			free(tmp);
			*b = true;
		}
		op = op->next;
	}
	return (true);
}

static void	delete_useless_ops(t_list *op, int *a)
{
	t_list	*tmp;
	t_list	*first_node;

	first_node = op;
	while (op)
	{
		if (op->next != NULL && do_we_delete(op) == true)
		{
			tmp = op->next->next;
			modify_prev_node(first_node, op, tmp);
			free(op->next->content);
			free(op->next);
			free(op->content);
			free(op);
			op = tmp;
			*a = true;
		}
		else
		{
			op = op->next;
		}
	}
}

int			op_reducer(t_list *op)
{
	int	a;
	int	b;

	a = true;
	b = true;
	while ((op != NULL) && (a == true || b == true))
	{
		if (a)
		{
			a = false;
			delete_useless_ops(op, &a);
		}
		if (b)
		{
			b = false;
			if ((shorten_ops(op, &b)) == false)
			{
				return (false);
			}
		}
	}
	return (true);
}

#include "push_swap.h"

static int		do_we_delete(t_list *i)
{
	if (i->next != NULL)
	{
		if (!ft_strcmp(i->content, PUSH_A) && !ft_strcmp(i->next->content, PUSH_B))
		{
			return (true);
		}
		if (!ft_strcmp(i->content, PUSH_B) && !ft_strcmp(i->next->content, PUSH_A))
		{
			return (true);
		}
		if (!ft_strcmp(i->content, ROT_A) && !ft_strcmp(i->next->content, REVROT_A))
		{
			return (true);
		}
		if (!ft_strcmp(i->content, REVROT_A) && !ft_strcmp(i->next->content, ROT_A))
		{
			return (true);
		}
		if (!ft_strcmp(i->content, ROT_B) && !ft_strcmp(i->next->content, REVROT_B))
		{
			return (true);
		}
		if (!ft_strcmp(i->content, REVROT_B) && !ft_strcmp(i->next->content, ROT_B))
		{
			return (true);
		}
	}
	return (false);
}

static char		*do_we_cut(t_list *i)
{
	if (i->next != NULL)
	{
		if (!ft_strcmp(i->content, SWAP_A) && !ft_strcmp(i->next->content, SWAP_B))
		{
			return (SWAP_BOTH);
		}
		if (!ft_strcmp(i->content, SWAP_B) && !ft_strcmp(i->next->content, SWAP_A))
		{
			return (SWAP_BOTH);
		}
		if (!ft_strcmp(i->content, ROT_A) && !ft_strcmp(i->next->content, ROT_B))
		{
			return (ROT_BOTH);
		}
		if (!ft_strcmp(i->content, ROT_B) && !ft_strcmp(i->next->content, ROT_A))
		{
			return (ROT_BOTH);
		}
		if (!ft_strcmp(i->content, REVROT_A) && !ft_strcmp(i->next->content, REVROT_B))
		{
			return (REVROT_BOTH);
		}
		if (!ft_strcmp(i->content, REVROT_B) && !ft_strcmp(i->next->content, REVROT_A))
		{
			return (REVROT_BOTH);
		}
	}
	return (NULL);
}

static void		modify_prev_node(t_list *first_node, t_list *op, t_list *new)
{
	while (first_node->next != op)
	{
		first_node = first_node->next;
	}
	first_node->next = new;
}

static int		shorten_ops(t_list *op, int *b)
{
	t_list	*tmp;
	char 	*shortcut;

	while (op)
	{
		if ((shortcut = do_we_cut(op)) != NULL)
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
		if (do_we_delete(op) == true)
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

int		op_reducer(t_list *op)
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
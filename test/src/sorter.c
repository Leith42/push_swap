#include "push_swap.h"

void	push_all_to_a_because_is_sorted_in_b(t_stack *b, t_stack *a)
{
	stack_push_on(a, b);
}

int		find_min_pos(t_stack *a)
{
	int		pos;
	int		i;

	i = -1;
	pos = 0;
	while (++i < a->log_len)
		if (a->elems[i] >= a->elems[pos])
			pos = i;
	return (pos);
}

int		is_sorted(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->log_len)
	{
		if (a->elems[i] <= a->elems[i + 1])
			i++;
		else
			return (-42);
	}
	return (42);
}

int		sorter(t_stack *a, t_stack *b)
{
	int		pos;

	while (!is_sorted(a) && a->log_len != 0)
	{
		if (b->log_len == 0 && is_sorted(a))
			return (42);
		else
		{
			pos = find_min_pos(a);
			if ((a->log_len - 1) - pos == 1)
			{
				swap(a);
				stack_push_on(b, a);	
			}
			else if (pos <= a->log_len / 2 )
				shift_down(a);
			else if (pos > a->log_len / 2)
				shift_up(a);
			else if ((pos == a->log_len - 1))
				stack_push_on(b, a);
		}
	}
	while (b->log_len == 0)
		push_all_to_a_because_is_sorted_in_b(b, a);
	return (42);
}

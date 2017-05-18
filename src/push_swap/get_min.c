#include "push_swap.h"

int get_min(t_stack *s)
{
	int min;

	min = s->data;
	s = s->next;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}
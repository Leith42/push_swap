#include "push_swap.h"

void	swap(t_stack *s)
{
	int		a;
	int		b;

	if (s->log_len <= 1)
		return ;
	a = s->log_len - 1;
	b = s->log_len - 2;
	s->elems[a] = s->elems[a] ^ s->elems[b];
	s->elems[b] = s->elems[a] ^ s->elems[b];
	s->elems[a] = s->elems[a] ^ s->elems[b];
}

void	stack_push_on(t_stack *a, t_stack *b)
{
	if (b->log_len <= 0)
		return ;
	//if (a->alloc_len == a->log_len)
	//{
		//a->alloc_len *= 2;
		//stack_grow(&a);
	//}
	stack_push(a, b->elems[b->log_len - 1]);
	stack_pop(b);
}

void	shift_up(t_stack *s)
{
	int		temp;
	int		recvry;
	int		i;

	recvry = s->log_len - 1;
	i = s->log_len - 1;
	temp = s->elems[recvry];
	while (recvry > 0)
		s->elems[i--] = s->elems[--recvry];
	s->elems[recvry] = temp;
}

void	shift_down(t_stack *s)
{
	int		temp;
	int		recvry;
	int		i;

	recvry = 0;
	i = 0;
	temp = s->elems[recvry];
	while (recvry < s->log_len - 1)
		s->elems[i++] = s->elems[++recvry];
	s->elems[i] = temp;
}

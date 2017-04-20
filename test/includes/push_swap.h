#ifndef PUSH_SWAP
#define PUSH_SWAP
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef struct	s_stack
{
	int			*elems;
	int			log_len;
	int			alloc_len;
}				t_stack;

void			stack_new(t_stack *s, int size);
void			stack_dispose(t_stack *s);
void			stack_push(t_stack *s, int val);
int				stack_pop(t_stack *s);
void			swap(t_stack *s);
void			stack_grow(t_stack **s);
void			stack_push_on(t_stack *a, t_stack *b);
void			shift_up(t_stack *s);
void			shift_down(t_stack *s);

#endif

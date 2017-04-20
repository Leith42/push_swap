#include "push_swap.h"
#include <stdio.h>

int		main()
{
	t_stack	*s;
	t_stack	*s1;
	int		j;

	j = 0;
	s1 = (t_stack *)malloc(sizeof(t_stack));
	s = (t_stack *)malloc(sizeof(t_stack));
	stack_new(s);
	stack_new(s1);
	s->elems[0] = 5;
	s->elems[1] = 8;
	s->elems[2] = 6;
	s->elems[3] = 3;
	s->elems[4] = 1;
	s->elems[5] = 2;
	s->log_len = 6;


	//Swap two
	j = s->log_len;
	printf("Testing Swap\n");
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}
	printf("After Swapping:\n");
	swap(s);
	j = s->log_len;
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}

	//Shift Up
	j = s->log_len;
	printf("\n\nTesting Shift-Up:\n");
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}
	printf("After shifting up:\n");
	shift_up(s);
	j = s->log_len;
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}
	//end Shift Up
	
	//Shift Down
	j = s->log_len;
	printf("\n\nTesting Shift-Down:\n");
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}
	printf("After Shifting Down:\n");
	shift_down(s);
	j = s->log_len;
	while(--j >= 0)
	{
		printf("%d\n", s->elems[j]);
	}
	//end shift down
	
	//Push on
	j = s->log_len;
	printf("\n\nTrying to push [%d] on stack b:\n", s->elems[s->log_len - 1]);
	while(--j >= 0)
		printf("%d\n", s->elems[j]);
	printf("Pushed: [%d] onto the stack\n", s->elems[s->log_len - 1]);
	stack_push_on(s1, s);
	j = s->log_len;
	while(--j >= 0)
		printf("%d\t%d\n", s->log_len >= 0 ? s->elems[j] : 0, s1->elems[j]);
	//end push on
	return (0);
	
	
	
}

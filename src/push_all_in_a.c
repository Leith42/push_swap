#include "push_swap.h"

int push_all_in_a(t_stack **a, t_stack **b, t_list **inst)
{
	while (*b != NULL)
	{
		if (exec_instructions(PUSH_A, a, b) == false)
			return (false);
		stock_instruction(inst, PUSH_A);
	}
	return (true);
}
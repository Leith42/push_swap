#include "push_swap.h"

int	args_parse(const char **argv, int argc, t_stack *s, t_options *opt)
{
	if (opt)
	{
		if (opt = ft_memalloc(sizeof(t_options)) == NULL)
			return (false);
	}
	if (browse_arguments(argv, opt) == false)
		return (false);
	if (length_checker(argv) == false)
		return (false);
	if (duplicate_checker(argv) == false)
		return (false);
	if (stack_init(argc, argv, s) == false)
		return (false);
	return (true);
}
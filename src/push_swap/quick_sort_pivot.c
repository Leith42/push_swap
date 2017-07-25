#include "push_swap.h"

static void	qs_swap(int *array, int a, int b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

static void	ft_qsort(int *array, int start, int end)
{
	int left;
	int right;
	int pivot;

	left = start - 1;
	right = end + 1;
	pivot = array[start];
	if (start >= end)
		return ;
	while (true)
	{
		while (array[--right] > pivot);
		while (array[++left] < pivot);
		if (left < right)
		{
			qs_swap(array, left, right);
		}
		else
			break ;
	}
	ft_qsort(array, start, right);
	ft_qsort(array, right + 1, end);
}

static int	*get_array_from_list(t_stack *s, int len)
{
	int *array;
	int i;

	i = 0;
	if ((array = malloc(sizeof(array) * len)) == NULL)
	{
		handle_error(s, NULL, NULL, NULL);

	}
	while (i < len)
	{
		array[i] = s->data;
		s = s->next;
		i++;
	}
	return (array);
}

int			get_pivot(t_stack *s, int len)
{
	int pivot;
	int *array;

	array = get_array_from_list(s, len);
	ft_qsort(array, 0, len);
	pivot = array[len >> 1];
	free (array);
	return (pivot);
}


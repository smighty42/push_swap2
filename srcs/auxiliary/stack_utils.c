#include "push_swap.h"
#include <unistd.h>

t_stack	*last_node(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	else
	{
		while (stack->next != NULL)
			stack = stack->next;
		return (stack);
	}
}
int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	* find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

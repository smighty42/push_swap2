#include "push_swap.h"
#include <unistd.h>
void	update_index(t_stack *a)
{
	int	i;
	int	median;

	i = 0;
	if (a == NULL)
		return ;
	median = stack_len(a) / 2;
	while (a != NULL)
	{
		a->index = i;
		if (i <= median)
			a->above_median = 1;
		else
			a->above_median = 0;
		a = a->next;
		i++;
	}
}
static void	setup_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	sign_index;

	while (a != NULL)
	{
		sign_index = LONG_MIN;
		current_b = b;
		while (current_b != NULL)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > sign_index)
			{
				sign_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (sign_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == 0)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
void	set_cheapest(t_stack *stack)
{
	long	cheapest_res;
	t_stack	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_res = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_res)
		{
			cheapest_res = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_a(t_stack **a, t_stack **b)
{
	update_index(*a);
	update_index(*b);
	setup_target_a(*a, *b);
	cost_analysis_a(*a, *b);
	set_cheapest(*a);
}
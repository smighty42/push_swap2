#include "push_swap.h"
#include <unistd.h>
void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
t_stack *get_cheapest(t_stack *stack)
{
    if(stack ==NULL)
        return NULL;
    while (stack!=NULL)
    {
        if(stack->cheapest)
            return(stack);
        stack = stack ->next;
    }
    return NULL;
}
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
void move_a_to_b(t_stack**a, t_stack **b)
{
    t_stack *cheapest_node;
    cheapest_node = get_cheapest(*a);  
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_two(a, b, cheapest_node);
    else if (!(cheapest_node->above_median)
        && !(cheapest_node->target_node->above_median))
    rev_rotate_two(a, b, cheapest_node);
    prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

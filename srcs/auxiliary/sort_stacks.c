#include "push_swap.h"

void rotate_two(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while(*b != cheapest_node->target_node && *a != cheapest_node)
        rr(a,b);
    update_index(*a);
    update_index(*b);
}
void rev_rotate_two(t_stack **a, t_stack **b, t_stack *chepest_node)
{
    while(*b != chepest_node->target_node && *a != chepest_node)
        rrr(a,b);
    update_index(*a);
    update_index(*b);
}
static void	min_on_top(t_stack **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if (find_min(*a)->above_median)
            ra(a);
        else
            rra(a);
    }
}	

void    sort_stacks(t_stack **a, t_stack **b)
{
    int len_a;

    len_a = stack_len(*a);
    if(len_a-- >3 && check_stack(*a) == 0)
        pb(a,b);
    if(len_a-- >3 && check_stack(*a) == 0)
        pb(a,b);
    while(len_a-- >3 && check_stack(*a) == 0)
    {
        init_nodes_a(a,b);
        move_a_to_b(a,b);
    }
    setup_three(a);
    while(*b)
    {
        init_nodes_b(*a,*b);
        move_b_to_a(a,b);
    }
    update_index(*a);
    min_on_top(a);
}
#include "push_swap.h"
#include <unistd.h>
t_stack    *max_node(t_stack *stack)
{
    long max;
    t_stack *max_node;

    if(stack==NULL)
        return NULL;
    
    max=LONG_MIN;
    
    while(stack!=NULL)
    {
        if(stack->nbr >max)
        {
            max=stack->nbr;
            max_node=stack;
        }
        stack= stack->next;
    }
    return max_node;
}
void    setup_three(t_stack **a)
{
    t_stack *big_node;

    big_node = max_node(*a);
    if(big_node == *a)
        ra(a);
    else if((*a)->next == big_node)
        rra(a);
    if(last_node(*a)== big_node)
        sa(a);
}
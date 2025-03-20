#include "push_swap.h"
#include <unistd.h>
#include "../libft/libft.h"

void add_node(t_stack **stack, int n)
{
    t_stack *sign_node;
    t_stack *node_last;

    if(stack == NULL )
        return;
    sign_node = ft_calloc(1,sizeof(t_stack));
    if(sign_node == NULL)
        return;
    sign_node->next=NULL;
    sign_node->nbr=n;
    if(*stack == NULL)
    {
        *stack=sign_node;
        sign_node->prev = NULL;
    }
    else
    {
        node_last = last_node(*stack);
        node_last->next = sign_node;
        sign_node->prev = node_last;
    }
}

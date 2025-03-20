/*ra (rotate a): a stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
rb (rotate b): b stackinin bütün elemanlarını bir yukarı kaydırın.
İlk eleman artık son eleman olacaktır.
rr : ra ve rb aksiyonlarının ikisini de çalıştır.*/
#include "push_swap.h"
#include <unistd.h>
#include "../printf/ft_printf.h"
static void rotate(t_stack **stack)
{   
    t_stack *sign_last;
    
    if(*stack==NULL || !(*stack)->next)
        return;

    sign_last = last_node(*stack);
    sign_last -> next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    sign_last->next->prev = sign_last;
    sign_last ->next->next =NULL;
}

void    ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void    rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
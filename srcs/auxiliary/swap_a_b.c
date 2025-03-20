/*sa (swap a): a stackinin en üstteki iki elemanını birbirileri ile yer değiştirin.
Eğer yalnızca bir eleman var ise veya hiç eleman yoksa bir şey yapmayın.
sb (swap b): b stackinin en üstteki iki elemanını birbirileri ile yer değiştirin.
Eğer yalnızca bir eleman var ise veya hiç eleman yoksa bir şey yapmayın.
ss : sa ve sb aksiyonlarının ikisini de çalıştır.*/
#include "push_swap.h"
#include <unistd.h>
#include "../printf/ft_printf.h"
static void swap(t_stack **head)
{
    if((head==NULL) || ((*head) -> next == NULL))
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if((*head)->next)
        (*head)->next->prev=(*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL;
}
void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}
void    sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}
void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}


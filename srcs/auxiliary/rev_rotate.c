// rra (reverse rotate a): a stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.
// rrb (reverse rotate b): b stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.
// rrr : rra ve rrb aksiyonlarının ikisini de çalıştırır.
#include "push_swap.h"
#include <unistd.h>
#include "../printf/ft_printf.h"
static void	rev_rotate(t_stack **stack)
{
	t_stack	*sign_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	else
	{
		sign_last = last_node(*stack);
		sign_last->prev->next = NULL;
		sign_last->next = *stack;
		sign_last->prev = NULL;
		*stack = sign_last;
		sign_last->next->prev = sign_last;
	}
}
void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}
void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}
void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

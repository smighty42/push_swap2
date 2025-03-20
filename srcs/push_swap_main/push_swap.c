#include "push_swap.h"
#include <unistd.h>
#include "../libft/libft.h"


static	void null_check(void *ptr)
{
	if (ptr == NULL)
		write_error();
	else
		return ;
}
int	check_stack(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (0);
	while(stack !=NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_setup_a(&a, av, ac == 2);
	}
	else
		stack_setup_a(&a, av, ac == 2);
	null_check(a);
	if (check_stack(a) == 0)
	{
		if(stack_len(a)==2)
			sa(&a);
		else if(stack_len(a)==3)
			setup_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_stack(&a),0);
}


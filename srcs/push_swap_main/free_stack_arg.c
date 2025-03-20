#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_args(char **av)
{
	int	i;

	i = 0;
	if (av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
void	free_stack(t_stack **stack)
{
	t_stack	*sign;
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	sign = *stack; 
	while (sign != NULL)
	{
		tmp = sign->next;
		sign->nbr =0;
		free(sign);
		sign = tmp;
	}
	*stack = NULL;
}

void	check_error(t_stack **a, char **av, int flag)
{
	if (flag)
		free_args(av);
	free_stack(a);
	write_error();
}

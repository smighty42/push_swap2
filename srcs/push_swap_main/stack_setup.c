#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
int	number_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i + j])
		j++;
	if (j > 11)
		return (1);
	while (str[i] != '\0')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] == '\0')
				return (i);
			i++;
		}
        return 1;
	}
	return (0);
}
int	syntax_check(char *str)
{
	if (number_check(str))
		return (1);
	if ((*str != '+' || *str != '-') || !(*str >= '0' && *str <= '9'))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
	
	return 0;
}
int	duplicate_number_error(t_stack *a, int n)
{
	if(a==NULL)
		return(0);
	while(a != NULL)
	{
		if(a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}
int ft_atollong(const char *s)
{
	long result;
	int sign;
	
	result = 0;
	sign = 1;

	while(*s == ' ' || *s == '\t')
		s++;
	if(*s == '-' || *s == '+')
	{
		if(*s == '-')
			sign = -1;
		s++;
	}
	while(*s!= '\0')
	{
		result = result*10 +(*s - '0');
		s++;
	}
	return(result*sign);
}

void	stack_setup_a(t_stack **a, char **av, int flag)
{
	long n;
	int i;
	i = 0;

	while (av[i] != NULL)
	{
		if (syntax_check(av[i])==1)
			check_error(a, av, flag);
		n = ft_atollong(av[i]);
		if (n> 2147483647 || n < -2147483648)
			check_error(a,av,flag);
		if (duplicate_number_error(*a,(int)n))
			check_error(a,av,flag);
		add_node(a,(int)n);
		i++;
	}
	if(flag)
		free(av);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayti <smayti@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:30:36 by smayti            #+#    #+#             */
/*   Updated: 2025/03/20 15:50:50 by smayti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa (push a): b stackinin en üstündeki elemanı a stackinin en üstüne koyun.
// Eğer b stacki boş ise bir şey yapmayın.
// pb (push b): a stackinin en üstündeki elemanı b stackinin en üstüne koyun.
// Eğer a stacki boş ise bir şey yapmayın.

#include "push_swap.h"
#include <unistd.h>
#include "../printf/ft_printf.h"

static void	push_a_b(t_stack **dest, t_stack **src)
{
	t_stack	*sign_node;

	if (src == NULL)
		return ;
	else
	{
		sign_node = *src;
		*src = (*src)->next;
		if (*src != NULL)
			(*src)->prev = NULL;
		sign_node->prev = NULL;
		if (dest == NULL)
		{
			*dest = sign_node;
			sign_node->prev = NULL;
		}
		else
		{
			sign_node->next = *dest;
			sign_node->next->prev = sign_node;
			*dest = sign_node;
		}
	}
}
void	pa(t_stack **a, t_stack **b)
{
	push_a_b(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push_a_b(b, a);
	ft_printf("pb\n");
}

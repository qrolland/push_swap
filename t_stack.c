/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:43:10 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:31 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackadd_back(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	stacklast(*stack)->next = new;
}

t_stack	*stacknew(int content)
{
	t_stack	*dest;

	dest = malloc(sizeof(t_stack));
	if (!dest)
		return (NULL);
	dest->value = content;
	dest->next = 0;
	dest->cost_a = -1;
	dest->cost_b = -1;
	dest->pos = -1;
	dest->target_pos = -1;
	dest->index = 0;
	return (dest);
}

int	stacksize(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:37:22 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:37:23 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	if (stacksize(*stack) >= 2)
	{
		tail = stacklast(*stack);
		head = *stack;
		*stack = (*stack)->next;
		tail->next = head;
		head->next = NULL;
	}
}

void	ra(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate_stack(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
}

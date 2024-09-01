/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:36:57 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:36:58 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*prev_tail;
	t_stack	*tail;

	if (stacksize(*stack) >= 2)
	{
		prev_tail = *stack;
		while (prev_tail->next->next)
			prev_tail = prev_tail->next;
		tail = prev_tail->next;
		prev_tail->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_putendl_fd("rrr", 1);
}

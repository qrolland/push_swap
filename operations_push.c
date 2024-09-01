/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:35:55 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:36:26 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (stacksize(*stack_src))
	{
		tmp = *stack_src;
		*stack_src = (*stack_src)->next;
		stackadd_front(stack_dst, tmp);
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

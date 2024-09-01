/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:40:08 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:37 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_for_3(t_stack **stack)
{
	int	max;

	max = stack_max_index(*stack);
	if ((*stack)->index == max)
		ra(stack);
	else if ((*stack)->next->index == max)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

static void	push_all_b_except3(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;

	size = stacksize(*stack_a);
	i = 0;
	while (size > 4 && i < size - 3 && i < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	while (i < size - 3)
	{
		pb(stack_a, stack_b);
		i++;
	}
}

static void	final_rotate(t_stack **stack_a)
{
	int	size;
	int	pos;

	stack_pos(stack_a);
	size = stacksize(*stack_a);
	pos = stack_min_index_pos(*stack_a);
	if (pos > size / 2)
	{
		while (pos < size)
		{
			rra(stack_a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_for_3(stack_a);
	else
	{
		push_all_b_except3(stack_a, stack_b);
		sort_for_3(stack_a);
		while (*stack_b)
		{
			stack_target_pos(stack_a, stack_b);
			stack_cost(stack_a, stack_b);
			find_do_cheap_move(stack_a, stack_b);
		}
		if (!stack_is_sort(*stack_a))
			final_rotate(stack_a);
	}
}

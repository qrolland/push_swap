/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:08:17 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:32:54 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//si on fait rra pour mettre au bon endroit (target_pos), le cost est négatif
void	stack_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;

	size_a = stacksize(*stack_a);
	size_b = stacksize(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = (size_b - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

void	move_cost(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			rrr(a, b);
			cost_a++;
			cost_b++;
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			rr(a, b);
			cost_a--;
			cost_b--;
		}
	}
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}

void	find_do_cheap_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheap = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
	cost_a = tmp->cost_a;
	cost_b = tmp->cost_b;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheap))
		{
			cheap = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_cost(stack_a, stack_b, cost_a, cost_b);
}

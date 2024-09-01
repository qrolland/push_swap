/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:38:33 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:39:52 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*fill_tab_stack(t_stack *stack_a)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * (stacksize(stack_a) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (stack_a)
	{
		tab[i] = stack_a->value;
		stack_a = stack_a->next;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	stack_index(t_stack **stack_a)
{
	int		*tab;
	t_stack	*tmp;
	int		i;

	tab = fill_tab_stack(*stack_a);
	ft_sort_int_tab(tab, ft_tabsize(tab));
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i] == tmp->value)
			{
				tmp->index = i + 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}

void	stack_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	target_position(t_stack *stack_a, int index)
{
	t_stack	*tmp;
	int		target_pos;
	int		target_index;

	tmp = stack_a;
	if (index < stack_max_index(stack_a))
	{
		target_index = stack_max_index(stack_a) + 1;
		while (tmp)
		{
			if (index < tmp->index && tmp->index < target_index)
			{
				target_pos = tmp->pos;
				target_index = tmp->index;
			}
			tmp = tmp->next;
		}
	}
	else
		target_pos = stack_min_index_pos(stack_a);
	return (target_pos);
}

void	stack_target_pos(t_stack **stack_a, t_stack	**stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	stack_pos(stack_a);
	stack_pos(stack_b);
	while (tmp)
	{
		tmp->target_pos = target_position(*stack_a, tmp->index);
		tmp = tmp->next;
	}
}

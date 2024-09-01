/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:21:01 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 17:21:01 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack_a, t_stack **stack_b);
void			sort_stack(t_stack **stack_a, t_stack **stack_b);
int				stacksize(t_stack *stack);
t_stack			*stacklast(t_stack *stack);
void			stackadd_front(t_stack **stack, t_stack *new);
t_stack			*stacknew(int content);
void			stackadd_back(t_stack **stack, t_stack *new);
int				stack_max_value(t_stack *stack);
int				stack_is_sort(t_stack *stack);
void			stack_target_pos(t_stack **stack_a, t_stack	**stack_b);
void			stack_cost(t_stack **stack_a, t_stack **stack_b);
void			find_do_cheap_move(t_stack **stack_a, t_stack **stack_b);
int				stack_min_index_pos(t_stack	*stack);
void			free_stack(t_stack *stack);
void			stack_pos(t_stack **stack);
int				stack_max_index(t_stack *stack);
void			stack_index(t_stack **stack_a);

#endif
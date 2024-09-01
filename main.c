/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:33:35 by qrolland          #+#    #+#             */
/*   Updated: 2022/12/20 16:46:28 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(char **argv, int nbr, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}

static int	check_error(char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		if (!ft_isint(argv[i]) || nbr > 2147483647 || nbr < -2147483648
			|| check_doubles(argv, nbr, i))
			return (1);
		i++;
	}
	return (0);
}

static void	fill_stack(t_stack **stack, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		stackadd_back(stack, stacknew(ft_atoi(argv[i])));
		i++;
	}		
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		if (check_error(argv))
			ft_error("Error");
		stack_b = 0;
		stack_a = 0;
		fill_stack(&stack_a, argv);
		stack_index(&stack_a);
		if (!stack_is_sort(stack_a))
			sort_stack(&stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}

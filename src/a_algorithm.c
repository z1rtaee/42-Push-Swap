/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:03:05 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/21 17:28:43 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	a_sort(t_stack **a, t_stack **b)
{
	int		a_len;
	t_stack	*cheapest;

	a_len = stack_len(*a);
	while (a_len > 3)
	{
		cheapest = a_cheapest_node(*a, *b);
		if (cheapest->type == R_R)
			execute_r_r(a, b, cheapest, 0);
		else if (cheapest->type == R_RV)
			execute_r_rv(a, b, cheapest, 0);
		else if (cheapest->type == RV_R)
			execute_rv_r(a, b, cheapest, 0);
		else if (cheapest->type == RV_RV)
			execute_rv_rv(a, b, cheapest, 0);
		pb(b, a);
		a_len--;
	}
}

void	execute_r_r(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int	double_moves;
	int	single_moves;

	double_moves = cheapest->index;
	if (cheapest->target < double_moves)
		double_moves = cheapest->target;
	single_moves = cheapest->cost - double_moves;
	while (double_moves--)
		rr(a, b);
	while (!flag && cheapest->index && single_moves--)
		ra(a);
	while (flag && cheapest->target && single_moves--)
	{
		ra(a);
		cheapest->target--;
	}
	while (single_moves--)
		rb(b);
}

void	execute_r_rv(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int	moves;

	if (!flag)
	{
		moves = stack_len(*b) - cheapest->target;
		while (cheapest->index)
			ra(a);
	}
	else
	{
		moves = stack_len(*b) - cheapest->index;
		while (cheapest->target)
		{
			ra(a);
			cheapest->target--;
		}
	}
	while (moves)
	{
		rrb(b);
		moves--;
	}
}

void	execute_rv_r(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int	moves;

	if (!flag)
	{
		moves = cheapest->target;
		while (cheapest->index)
			rra(a);
	}
	else
	{
		moves = cheapest->index;
		while (cheapest->target < stack_len(*a))
		{
			rra(a);
			cheapest->target++;
		}
	}
	while (moves)
	{
		rb(b);
		moves--;
	}
}

void	execute_rv_rv(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int	double_moves;
	int	single_moves;

	if (!flag)
	{
		double_moves = stack_len(*a) - cheapest->index;
		if (stack_len(*b) - cheapest->target < double_moves)
			double_moves = stack_len(*b) - cheapest->target;
	}
	else
	{
		double_moves = stack_len(*b) - cheapest->index;
		if (stack_len(*a) - cheapest->target < double_moves)
			double_moves = stack_len(*a) - cheapest->target;
	}
	single_moves = cheapest->cost - double_moves;
	while (double_moves--)
		rrr(a, b);
	while (!flag && cheapest->index && single_moves--)
		rra(a);
	while (flag && cheapest->target++ < stack_len(*a) && single_moves--)
		rra(a);
	while (single_moves--)
		rrb(b);
}

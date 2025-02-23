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
			execute_r_r(a, b, cheapest);
		else if (cheapest->type == R_RV)
			execute_r_rv(a, b, cheapest, 0);
		else if (cheapest->type == RV_R)
			execute_rv_r(a, b, cheapest, 0);
		else if (cheapest->type == RV_RV)
			execute_rv_rv(a, b, cheapest);
		pb(b, a);
		a_len--;
	}
}

void	execute_r_r(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	double_moves;
	int	single_moves;

	double_moves = cheapest->index;
	if (cheapest->target < double_moves)
		double_moves = cheapest->target;
	single_moves = (cheapest)->cost - double_moves;
	while (double_moves)
	{
		rr(a, b);
		double_moves--;
	}
	while (cheapest->index && single_moves)
	{
		ra(a);
		single_moves--;
	}
	while (single_moves)
	{
		rb(b);
		single_moves--;
	}
}

void	execute_r_rv(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int moves;
	
	moves =  stack_len(*b) - cheapest->target;
	while (cheapest->index)
		ra(a);
	while (moves)
	{
		rrb(b);
		moves--;
	}
}

void	execute_rv_r(t_stack **a, t_stack **b, t_stack *cheapest, int flag)
{
	int moves;

	moves = cheapest->index;
	while ((*a)->index)
		rra(a);
	while (moves)
	{
		rb(b);
		moves--;
	}
}

void	execute_rv_rv(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	double_moves;
	int	single_moves;

	double_moves = cheapest->index;
	if (cheapest->target < double_moves)
		double_moves = cheapest->target;
	single_moves = cheapest->cost - double_moves;
	while (double_moves)
	{
		rrr(a, b);
		double_moves--;
	}
	while (cheapest->index && single_moves)
	{
		rra(a);
		single_moves--;
	}
	while (single_moves)
	{
		rrb(b);
		single_moves--;
	}
}

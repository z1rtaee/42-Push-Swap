/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_cheapest_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:07:19 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/21 14:25:45 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*a_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	int		a_len;
	int		b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	a_set_target(a, b);
	a_cost_rvr_rvrv(a, a_len, b_len, a_cost_rr_rrv(a, b_len));
	cheapest = a;
	a = a->next;
	while (a)
	{
		a_set_target(a, b);
		a_cost_rvr_rvrv(a, a_len, b_len, a_cost_rr_rrv(a, b_len));
		if (a->cost < cheapest->cost)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}

void	a_set_target(t_stack *a, t_stack *b)
{
	int	target_nbr;
	int	index;

	if (!b)
		return ;
	if (a->content > get_max(b)->content || a->content < get_min(b)->content)
	{
		a->target = get_max(b)->index;
		return ;
	}
	target_nbr = INT_MIN;
	while (b)
	{
		if (b->content > target_nbr && b->content < a->content)
		{
			target_nbr = b->content;
			index = b->index;
		}
		b = b->next;
	}
	a->target = index;
}

int	a_cost_rr_rrv(t_stack *a, int b_len)
{
	int	cost;

	if (a->index > a->target)
		cost = a->index;
	else
		cost = a->target;
	a->type = R_R;
	if (a->index + (b_len - a->target) < cost)
	{
		cost = a->index + (b_len - a->target);
		a->type = R_RV;
	}
	return (cost);
}

int	a_cost_rvr_rvrv(t_stack *a, int a_len, int b_len, int cost)
{
	if ((a_len - a->index) + a->target < cost)
	{
		cost = (a_len - a->index) + a->target;
		a->type = RV_R;
	}
	if (a_len - a->index > b_len - a->target && a_len - a->index < cost)
	{
		cost = a_len - a->index;
		a->type = RV_RV;
	}
	else if (a_len - a->index < b_len - a->target && b_len - a->target < cost)
	{
		cost = b_len - a->target;
		a->type = RV_RV;
	}
	a->cost = cost;
	return (cost);
}

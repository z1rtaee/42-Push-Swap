/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cheapest_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:55:45 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/21 14:27:54 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*b_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	int		a_len;
	int		b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	b_set_target(a, b);
	b_cost_rvr_rvrv(b, a_len, b_len, b_cost_rr_rrv(b, b_len));
	cheapest = b;
	b = b->next;
	while (b)
	{
		b_set_target(a, b);
		b_cost_rvr_rvrv(b, a_len, b_len, b_cost_rr_rrv(b, b_len));
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

void	b_set_target(t_stack *a, t_stack *b)
{
	int	target_nbr;
	int	index;

	if (!a)
		return ;
	if (b->content > get_max(a)->content || b->content < get_min(a)->content)
	{
		b->target = get_min(a)->index;
		return ;
	}
	target_nbr = INT_MAX;
	while (a)
	{
		if (a->content < target_nbr && a->content > b->content)
		{
			target_nbr = a->content;
			index = a->index;
		}
		a = a->next;
	}
	b->target = index;
}

int	b_cost_rr_rrv(t_stack *b, int b_len)
{
	int	cost;

	if (b->index > b->target)
		cost = b->index;
	else
		cost = b->target;
	b->type = R_R;
	if (b->target + (b_len - b->index) < cost)
	{
		cost = b->target + (b_len - b->index);
		b->type = R_RV;
	}
	return (cost);
}

int	b_cost_rvr_rvrv(t_stack *b, int a_len, int b_len, int cost)
{
	if ((a_len - b->target) + b->index < cost)
	{
		cost = (a_len - b->target) + b->index;
		b->type = RV_R;
	}
	if (b_len - b->index > a_len - b->target && b_len - b->index < cost)
	{
		cost = b_len - b->index;
		b->type = RV_RV;
	}
	else if (b_len - b->index < a_len - b->target && a_len - b->target < cost)
	{
		cost = a_len - b->target;
		b->type = RV_RV;
	}
	b->cost = cost;
	return (cost);
}

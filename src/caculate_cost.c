/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caculate_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:07:19 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/12 19:52:32 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack *a_cheapest_node(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	int		a_len;

	a_len = stack_len(a);
	while (a)
	{
		a_set_target(a, b);

	}
}

void	a_set_target(t_stack *a, t_stack *b)
{
	int	target_nbr;
	int	index;

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

int	cost_rr_rrv(t_stack *a, int b_len)
{
	int	cost;
	int	a_len;

	a_len = stack_len(a);
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

int	cost_rvr_rvrv(t_stack *a, int b_len, int cost)
{
	int	a_len;

	a_len = stack_len(a);
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
	return (cost);
}

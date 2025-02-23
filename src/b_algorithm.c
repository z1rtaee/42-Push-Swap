/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:15:54 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/21 16:49:38 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	b_sort(t_stack **a, t_stack **b)
{
	int	b_len;
	t_stack *cheapest;

	b_len = stack_len(*b);
	while (b_len > 0)
	{
		cheapest = b_cheapest_node(*a, *b);
		if (cheapest->type == R_R)
			execute_r_r(a, b);
		if (cheapest->type == R_RV)
			execute_r_rv(a, b);
		if (cheapest->type == RV_R)
			execute_rv_r(a, b);
		if (cheapest->type == RV_RV)
			execute_rv_rv(a, b);
		pa(a, b);
		b_len--;
	}
}

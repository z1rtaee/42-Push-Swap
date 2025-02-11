/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:58:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/11 19:09:17 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

void	sort_three(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*max_val;

	tmp = (*a)->next;
	max_val = *a;
	while (tmp)
	{
		if (tmp->content > max_val->content)
			max_val = tmp;
		tmp = tmp->next;
	}
	if (max_val->index == 2 && !is_sorted(*a))
		sa(a);
	else if (!max_val->index)
	{
		ra(a);
		if (!is_sorted(*a))
			sa(a);
	}
	else
	{
		rra(a);
		if (!is_sorted(*a))
			sa(a);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2 && !is_sorted(*a))
		sa(a);
	if	(stack_len(*a) == 3)
		sort_three(a);
	if (stack_len(*a) > 3)
	{
		
	}
}

	
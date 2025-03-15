/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:58:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/03/12 18:55:08 by bpires-r         ###   ########.fr       */
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

t_stack	*get_max(t_stack *x)
{
	t_stack	*max_val;

	max_val = x;
	x = x->next;
	while (x)
	{
		if (x->content > max_val->content)
			max_val = x;
		x = x->next;
	}
	return (max_val);
}

t_stack	*get_min(t_stack *x)
{
	t_stack	*min_val;

	min_val = x;
	x = x->next;
	while (x)
	{
		if (x->content < min_val->content)
			min_val = x;
		x = x->next;
	}
	return (min_val);
}

void	sort_three(t_stack **a)
{
	t_stack	*max_val;

	max_val = get_max(*a);
	if (max_val->index == 2 && !is_sorted(*a))
		sa(a, 1);
	else if (!max_val->index)
	{
		ra(a, 1);
		if (!is_sorted(*a))
			sa(a, 1);
	}
	else if (max_val->index == 1)
	{
		rra(a, 1);
		if (!is_sorted(*a))
			sa(a, 1);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2 && !is_sorted(*a))
		sa(a, 1);
	if (stack_len(*a) == 3)
		sort_three(a);
	if (stack_len(*a) > 3)
	{
		pb(b, a, 1);
		pb(b, a, 1);
		a_sort(a, b);
		sort_three(a);
	}
	if (*b)
		b_sort(a, b);
	if (get_min(*a)->index < stack_len(*a) / 2)
		while (get_min(*a)->index)
			ra(a, 1);
	else
		while (get_min(*a)->index)
			rra(a, 1);
}

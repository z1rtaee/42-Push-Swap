/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:58:56 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/21 17:25:49 by bpires-r         ###   ########.fr       */
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
	t_stack *temp;

	if (stack_len(*a) == 2 && !is_sorted(*a))
		sa(a);
	if (stack_len(*a) == 3)
		sort_three(a);
	if (stack_len(*a) > 3)
	{
		pb(b, a);
		pb(b, a);
		temp = *a;
		while (temp)
		{
			printf("Stack A value -> %ld\n", temp->content);
			temp = temp->next;
		}
		printf("\n");
		temp = *b;
		while (temp)
		{
			printf("Stack B value -> %ld\n", temp->content);
			temp = temp->next;
		}
		printf("A Algorithm Operations: \n");	
		a_sort(a, b);
		sort_three(a);
		temp = *a;
		while (temp)
		{
			printf("Stack A value After Sort three -> %ld\n", temp->content);
			temp = temp->next;
		}
		temp = *b;
		while (temp)
		{
			printf("Stack B value -> %ld\n", temp->content);
			temp = temp->next;
		}
	}
	if (*b)
		b_sort(a, b);
}

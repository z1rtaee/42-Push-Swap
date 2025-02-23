/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:45:06 by zirtaee           #+#    #+#             */
/*   Updated: 2025/02/10 17:32:32 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack **to, t_stack **from)
{
	t_stack	*tmp;

	if (!from || !*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	tmp->prev = NULL;
	*to = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->index++;
		tmp = tmp->next;
	}
	tmp = *from;
	while (tmp)
	{
		tmp->index--;
		tmp = tmp->next;
	}
}

void	swap(t_stack **x)
{
	int	tmp;

	if (!x || !*x || !(*x)->next)
		return ;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
}

void	rotate(t_stack **x)
{
	t_stack	*first;
	t_stack	*last;

	if (!x || !*x || !(*x)->next)
		return ;
	first = *x;
	first->index = stack_len(*x) - 1;
	first = first->next;
	while (first)
	{
		first->index--;
		first = first->next;
	}
	first = *x;
	last = (t_stack *)ft_lstlast((t_list *)(*x));
	*x = first->next;
	(*x)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rv_rotate(t_stack **x)
{
	t_stack	*last;
	t_stack	*sec_last;

	if (!x || !*x || !(*x)->next)
		return ;
	last = (t_stack *)ft_lstlast((t_list *)(*x));
	sec_last = last->prev;
	sec_last->next = NULL;
	last->next = *x;
	last->prev = NULL;
	(*x)->prev = last;
	*x = last;
	last->index = 0;
	last = last->next;
	while (last)
	{
		last->index++;
		last = last->next;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rv_rotate(a);
	rv_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:45:06 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/20 18:35:33 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack **x, t_stack **y)
{
	t_stack	*tmp;

	if (!y || !*y)
		return ;
	tmp = *y;
	*y = (*y)->next;
	if (*y)
		(*y)->prev = NULL;
	tmp->next = *x;
	if (*x)
		(*x)->prev = tmp;
	tmp->prev = NULL;
	*x = tmp;
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
}

void	rrr(t_list **a, t_stack **b)
{
	rv_rotate(a);
	rv_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}

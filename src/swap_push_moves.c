/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:41:48 by zirtaee           #+#    #+#             */
/*   Updated: 2025/03/10 05:28:04 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_stack **a, t_stack **b, int flag)
{
	push(a, b);
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	push(b, a);
	if (flag)
		ft_putstr_fd("pb\n", 1);
}

void	sa(t_stack **a, int flag)
{
	swap(a);
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int flag)
{
	swap(b);
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	swap(a);
	swap(b);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}

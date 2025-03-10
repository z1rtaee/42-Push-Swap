/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_revotate_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:00:52 by zirtaee           #+#    #+#             */
/*   Updated: 2025/03/10 05:27:08 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stack **a, int flag)
{
	rotate(a);
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int flag)
{
	rotate(b);
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag)
		ft_putstr_fd("rr\n", 1);
}

void	rra(t_stack **a, int flag)
{
	rv_rotate(a);
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int flag)
{
	rv_rotate(b);
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

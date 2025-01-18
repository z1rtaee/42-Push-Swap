/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:45:06 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/17 21:25:02 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    push(t_stack **x, t_stack **y)
{
    t_stack *tmp;

    if (!y || !*y)
        return ;
    tmp = *y;
    *y = (*y)->next;
    (*y)->prev = NULL;
    tmp->next = *x;
    (*x)->prev = tmp;
    tmp->prev = NULL;
    *x = tmp;
}

void    swap(t_stack **x)
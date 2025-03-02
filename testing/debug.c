/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:25:39 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/20 18:37:11 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp)
	{
		printf("Node Content : %d\n", tmp->content);
		if (tmp->prev)
			printf("Node Prev : %d\n", tmp->prev->content);
		else
			printf("No Prev found.\n");
		if (tmp->next)
			printf("Node Next : %d\n\n", tmp->next->content);
		else
			printf("No Next found\n\n");
		tmp = tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACTUAL_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:15:13 by bpires-r          #+#    #+#             */
/*   Updated: 2025/02/11 15:45:51 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0]))
		return (1);
	if(!check_input(argc, argc))
		return (ft_putchar_fd("Error", 2), 1);
	create_stack(&a, argv);
	if (!check_dup(a) || !check_max(a))
		return (free_stack(&a), ft_putendl_fd("Error", 2), 1);
	if (!is_sorted(a))
		sort_all(&a);
	free_stack(&a);
}
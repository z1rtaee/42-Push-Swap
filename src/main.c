/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:19:18 by zirtaee           #+#    #+#             */
/*   Updated: 2025/03/10 00:56:16 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1 || !argv[1][0])
		return (1);
	a = NULL;
	b = NULL;
	if (!check_input(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	create_stack(&a, argv);
	if (!check_dup(a) || !check_max(a))
		return (free_stack(&a), ft_putendl_fd("Error", 2), 1);
	if (is_sorted(a))
		return (free_stack(&a), 1);
	if (!is_sorted(a) || !is_sorted(b))
		sort_all(&a, &b);
	free_stack(&a);
	return (0);
}

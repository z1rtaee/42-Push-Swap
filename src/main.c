/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:19:18 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/17 19:56:29 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		exit (1);
	a = NULL;
	if (!check_input(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	create_stack(&a, argv);
	if (!check_dup(a))
		return (free_stack(&a), ft_putendl_fd("Error", 2), 1);
	return (0);
}

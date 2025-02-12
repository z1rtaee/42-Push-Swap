/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:19:18 by zirtaee           #+#    #+#             */
/*   Updated: 2025/02/12 15:00:46 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	// t_stack	*b;
	t_stack *temp;

	if (argc == 1 || !argv[1][0])
		return (1);
	a = NULL;
	// b = NULL;
	if (!check_input(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	create_stack(&a, argv);
	if (!check_dup(a) || !check_max(a))
		return (free_stack(&a), ft_putendl_fd("Error", 2), 1);
	if (is_sorted(a))
		return (free_stack(&a), 1);
	else 
		sort_all(&a);
	temp = a;
	while (temp)
	{
		printf("Stack A value -> %ld\n", temp->content);
		temp = temp->next;
	}
	free_stack(&a);
	// temp = b;
	// while (temp)
	// {
	// 	printf("Stack B value -> %d\n", temp->content);
	// 	temp = temp->next;
	// }
	// printf("\n");
	// rv_rotate(&a);
	// temp = a;
	// printf("\e[1;35mSTACK A :\n\e[0m");
	// printf("\n");
	// while (temp)
    // {
    //     printf("Node Content : %d\n", temp->content);
    //     if (temp->prev)
    //         printf("Node Prev : %d\n", temp->prev->content);
    //     else
    //         printf("No Prev found.\n");
    //     if (temp->next)
    //         printf("Node Next : %d\n\n", temp->next->content);
    //     else
    //         printf("No Next found.\n\n");
    //     temp = temp->next;
    // }
	// temp = b;
	// printf("\e[1;35mSTACK B :\n\e[0m");
	// while (temp)
    // {
    //     printf("Node Content : %d\n", temp->content);
    //     if (temp->prev)
    //         printf("Node Prev : %d\n", temp->prev->content);
    //     else
    //         printf("No Prev found.\n");
    //     if (temp->next)
    //         printf("Node Next : %d\n\n", temp->next->content);
    //     else
    //         printf("No Next found.\n\n");
    //     temp = temp->next;
    // }
	return (0);
}

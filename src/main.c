/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:19:18 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/16 22:53:06 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;

    a = NULL;
    create_stack(&a, argv);
    while (a)
    {
        printf("Content -> %d\n", a->content);
        a = a->next;
    }
    printf("%d\n", check_input(argc, argv));
    return(0);
}
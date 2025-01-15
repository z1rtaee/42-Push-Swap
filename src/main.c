/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:19:18 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/15 22:18:51 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    printf("%d\n", check_input(argc, argv));
    printf("%d\n", check_dup(argc, argv)); 
    return(0);
}
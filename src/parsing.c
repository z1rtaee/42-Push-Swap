/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:55:03 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/15 19:58:17 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int check_num(int argc, char **argv)
{
    int x;
    int y;
    
    x = 1;
    while (x < argc)
    {
        y = 0;
        if ((argv[x][y] == '-' || argv[x][y] == '+') ft_strlen(argv[x] > 1))
            y++;
        while (argv[x][y])
        {
            if (!ft_isdigit(argv[x][y]))
                return (FALSE);
            y++;
        }
        x++;
    }
    return (TRUE);
}

// int check_dup(int argc, char **argv)
// {
//     int x;
//     int y;

//     x = 1;
//     while (x < argc)
// }

// int check_input(int argc, char **argv)
// {
//     if (argc == 1)
//         exit (1);
//     if (!check_num(argc, argv))
//         return (FALSE);
//     if ()
// }
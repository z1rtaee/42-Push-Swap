/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:55:03 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/15 22:27:32 by zirtaee          ###   ########.fr       */
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
        if ((argv[x][y] == '-' || argv[x][y] == '+') && (ft_strlen(argv[x]) > 1))
            y++;
        while (argv[x][++y])
        {
            if (!ft_isdigit(argv[x][y]) )
                return (FALSE);
        }
        x++;
    }
    return (TRUE);
}

int check_dup(int argc, char **argv)
{
    int i;
    int j;
    int aux;
    
    i = 1;
    while (i < argc - 1)
    {
        j = i + 1;
        aux = ft_atoi(argv[i]);
        while (j < argc)
        {
            if (aux == ft_atoi(argv[j]))
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int check_input(int argc, char **argv)
{
    int     x;
    int     i;
    char    **tmp;
    
    if (argc == 1)
        exit (1);
    x = 0;
    while (++x < argc)
    {
        i = 0;
        tmp = ft_split(argv[x], ' ');
        if (!tmp)
            return (FALSE);
        while (tmp[++i]);
        if (!check_num(i, tmp))
            return (FALSE);
    }
    return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:40 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/16 22:49:55 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
    int             content;
    struct s_stack  *next;
    struct s_stack   *prev;
}                   t_stack;

int     main(int argc, char **argv);
int     check_num(int argc, char **argv);
int     check_dup(int argc, char **argv);
int     check_input(int argc, char **argv);
t_stack *create_node(int nbr);
void    create_stack(t_stack **a, char **argv);
void    add_back(t_stack **a, t_stack *new);
void    free_ar(char **ar);

#endif
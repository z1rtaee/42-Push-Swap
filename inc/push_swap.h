/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:40 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/15 22:19:24 by zirtaee          ###   ########.fr       */
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
    struct s_list   *prev;
    void            *content;
    struct s_list   *next;
}                   t_stack;

int check_num(int argc, char **argv);
int check_dup(int argc, char **argv);
int check_input(int argc, char **argv);
int main(int argc, char **argv);

#endif
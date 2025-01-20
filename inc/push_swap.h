/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:40 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/20 19:12:42 by zirtaee          ###   ########.fr       */
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
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//Main function
int		main(int argc, char **argv);

//Functions for input validation
int		check_num(int argc, char **argv);
int		check_dup(t_stack *a);
int		check_input(int argc, char **argv);

//Functions for stack utility
t_stack	*create_node(int nbr);
void	create_stack(t_stack **a, char **argv);
void	stack_add_back(t_stack **a, t_stack *new);
void	stack_add_front(t_stack **a, t_stack *new);
void	print_stack(t_stack *x);
int		stack_len(t_stack *x);

//Memory handle functions
void	free_stack(t_stack **stack);
void	free_ar(char **ar);

//Moves and operations
void	push(t_stack **x, t_stack **y);
void	swap(t_stack **x);
void	rotate(t_stack **x);
void	rv_rotate(t_stack **x);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_list **a, t_stack **b);

#endif
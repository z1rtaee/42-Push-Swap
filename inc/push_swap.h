/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:21:40 by zirtaee           #+#    #+#             */
/*   Updated: 2025/02/21 17:24:37 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef enum s_rot_type
{
	R_R,
	R_RV,
	RV_R,
	RV_RV
}				t_rot_type;

typedef struct s_stack
{
	long			content;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
	int				target;
	int				cost;
	t_rot_type		type;
}				t_stack;

//Main function
int		main(int argc, char **argv);

//Functions for input validation
int		check_num(int argc, char **argv);
int		check_dup(t_stack *a);
int		check_input(int argc, char **argv);
int		check_max(t_stack *a);

//Functions for stack utility
t_stack	*create_node(long nbr);
void	create_stack(t_stack **a, char **argv);
void	stack_add_back(t_stack **a, t_stack *new);
void	print_stack(t_stack *x);
int		stack_len(t_stack *x);

//Memory handle functions
void	free_stack(t_stack **stack);
void	free_ar(char **ar);

//Moves and operations
void	push(t_stack **to, t_stack **from);
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
void	rrr(t_stack **a, t_stack **b);

//Functions for sort utility 
t_stack *get_max(t_stack *x);
t_stack	*get_min(t_stack *x);
int		is_sorted(t_stack *a);
void	sort_three(t_stack **a);
void	sort_all(t_stack **a, t_stack **b);

//Turk Algorithm
void	execute_r_r(t_stack **a, t_stack **b, t_stack *cheapest);
void	execute_r_rv(t_stack **a, t_stack **b, t_stack *cheapest, int flag);
void	execute_rv_r(t_stack **a, t_stack **b, t_stack *cheapest, int flag);
void	execute_rv_rv(t_stack **a, t_stack **b, t_stack *cheapest);

//Turk Algorithm Stack A
t_stack	*a_cheapest_node(t_stack *a, t_stack *b);
void	a_set_target(t_stack *a, t_stack *b);
int		a_cost_rr_rrv(t_stack *a, int b_len);
int		a_cost_rvr_rvrv(t_stack *a, int b_len, int cost);
void	a_sort(t_stack **a, t_stack **b);

//Turk Algorithm Stack B
t_stack	*b_cheapest_node(t_stack *a, t_stack *b);
void	b_set_target(t_stack *a, t_stack *b);
int		b_cost_rr_rrv(t_stack *b, int a_len);
int		b_cost_rvr_rvrv(t_stack *b, int a_len, int cost);
void	b_sort(t_stack **a, t_stack **b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:08:54 by bpires-r          #+#    #+#             */
/*   Updated: 2025/03/10 00:04:24 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_error(t_stack **a, char *line)
{
	ft_putendl_fd("Error", 2);
	free_stack(a);
	free(line);
	exit (0);
}

void	execute_opperations(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(b, a);
	else
		put_error(a, line);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc == 1 || !argv[1][0])
		return (1);
	a = NULL;
	b = NULL;
	if (!check_input(argc, argv))
		return (ft_putendl_fd("Error", 2), 1);
	create_stack(&a, argv);
	if (!check_dup(a) || !check_max(a))
		return (free_stack(&a), ft_putendl_fd("Error", 2), 1);
	line = get_next_line(0);
	while (line)
	{
		execute_opperations(&a, &b, line);
		line = get_next_line(0);
	}
	if (!is_sorted(a) || b)
		ft_putendl_fd("KO", 2);
	else
		ft_putendl_fd("OK", 1);
	return (free_stack(&a), free_stack(&b), 0);
}

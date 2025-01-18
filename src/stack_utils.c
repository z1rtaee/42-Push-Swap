/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:53:17 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/17 19:39:35 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*create_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = nbr;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (!a || !new)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = (t_stack *)ft_lstlast((t_list *)(*a));
	last->next = new;
	new->prev = last;
}

void	stack_add_front(t_stack **a, t_stack *new)
{
	if (!a || !new)
		return ;
	if (!*a)
		*a = new;
	new->next = *a;
	(*a)->prev = new;
	*a = new;
}

void	create_stack(t_stack **a, char **argv)
{
	t_stack	*new;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		tmp = ft_split(argv[i], ' ');
		j = -1;
		while (tmp[++j])
		{
			new = create_node(ft_atoi(tmp[j]));
			if (!new)
				return (free_ar(tmp));
			add_back(a, new);
		}
		free_ar(tmp);
	}
}

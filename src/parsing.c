/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:55:03 by zirtaee           #+#    #+#             */
/*   Updated: 2025/01/17 19:08:54 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_num(int argc, char **argv)
{
	int	x;
	int	y;

	x = 0;
	while (x < argc)
	{
		y = 0;
		if ((argv[x][y] == '-' || argv[x][y] == '+')
			&& (ft_strlen(argv[x]) > 1))
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

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->content == a->content)
				return (FALSE);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (TRUE);
}

int	check_input(int argc, char **argv)
{
	int		x;
	int		i;
	char	**tmp;

	x = 0;
	while (++x < argc)
	{
		i = 0;
		tmp = ft_split(argv[x], ' ');
		if (!tmp)
			return (FALSE);
		while (tmp[i])
			i++;
		if (!check_num(i, tmp))
			return (FALSE);
	}
	return (TRUE);
}

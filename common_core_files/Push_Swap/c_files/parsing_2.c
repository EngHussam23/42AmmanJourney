/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:51:44 by halragga          #+#    #+#             */
/*   Updated: 2026/02/06 19:54:19 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_to_stack(t_stack **stk, int val)
{
	t_stack	*new_n;
	t_stack	*crnt;

	new_n = create_node(val);
	if (!*stk)
	{
		*stk = new_n;
		return ;
	}
	crnt = *stk;
	while (crnt->next)
		crnt = crnt->next;
	crnt->next = new_n;
}

t_stack	*create_node(int val)
{
	t_stack	*new_n;

	new_n = (t_stack *)malloc(sizeof(t_stack));
	if (!new_n)
		ft_exit_error(5);
	new_n->value = val;
	new_n->index = -1;
	new_n->next = NULL;
	return (new_n);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > LONG_MAX / 10
			|| (res == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10))
			ft_exit_error(4);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

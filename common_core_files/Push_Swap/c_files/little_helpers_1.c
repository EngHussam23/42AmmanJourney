/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_helpers_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:52:59 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 12:20:37 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

void	free_stack(t_stack **stack)
{
	t_stack	*crnt;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	crnt = *stack;
	while (crnt)
	{
		next = crnt->next;
		free(crnt);
		crnt = next;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack *crnt;

	if (!stack)
		return (1);
	crnt = stack;
	while (crnt->next)
	{
		if (crnt->value > crnt->next->value)
			return (0);
		crnt = crnt->next;
	}
	return (1);
}

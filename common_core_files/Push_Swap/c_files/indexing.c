/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:30:37 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 17:04:27 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Get the size of the stack
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// Indexing helper 1: finds the minimum value that hasn't been indexed
static int	find_min(t_stack *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->index == -1 && stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

// Indexing helper 2: indexes the minimum value in the stack
static void	give_min_index(t_stack *stack, int min, int index)
{
	while (stack)
	{
		if (stack->value == min)
			stack->index = index;
		stack = stack->next;
	}
}

// Indexing the the stack nodes
void	give_index(t_stack *stack)
{
	int		size;
	int		min;
	int		i;

	size = get_stack_size(stack);
	i = 0;
	while (i < size)
	{
		min = find_min(stack);
		give_min_index(stack, min, i);
		i++;
	}
}

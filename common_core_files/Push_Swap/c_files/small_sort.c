/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:24:23 by halragga          #+#    #+#             */
/*   Updated: 2026/02/01 16:08:57 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*crnt;

	crnt = stack;
	min = crnt->value;
	pos = 0;
	min_pos = 0;
	while (crnt)
	{
		if (crnt->value < min)
		{
			min = crnt->value;
			min_pos = pos;
		}
		crnt = crnt->next;
		pos++;
	}
	return (min_pos);
}

static void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap_a_op(stack);
}

static void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		swap_a_op(stack);
	else if (a > b && b > c)
	{
		swap_a_op(stack);
		rev_rot_a(stack);
	}
	else if (a > b && b < c && a > c)
		rotate_a_op(stack);
	else if (a < b && b > c && a < c)
	{
		swap_a_op(stack);
		rotate_a_op(stack);
	}
	else if (a < b && b > c && a > c)
		rev_rot_a(stack);
}

// Sort 4 - g elements: push to B, sort 3, push back.
static void	sort_five(t_stack **stk_a, t_stack **stk_b)
{
	int	size;
	int	min_pos;

	size = get_stack_size(*stk_a);
	while (size > 3)
	{
		min_pos = find_min_pos(*stk_a);
		if (min_pos <= size / 2)
		{
			while (min_pos--)
				rotate_a_op(stk_a);
		}
		else
		{
			while (min_pos++ < size)
				rev_rot_a(stk_a);
		}
		push_to_b_op(stk_a, stk_b);
		size--;
	}
	sort_three(stk_a);
	while (*stk_b)
		push_to_a_op(stk_a, stk_b);
}

void	sort_stack(t_stack **stk_a, t_stack **stk_b)
{
	int	size;

	size = get_stack_size(*stk_a);
	if (size == 2)
		sort_two(stk_a);
	else if (size == 3)
		sort_three(stk_a);
	else if (size <= 5)
		sort_five(stk_a, stk_b);
	else
	{
		give_index(*stk_a);
		radix_sort(stk_a, stk_b);
	}
}

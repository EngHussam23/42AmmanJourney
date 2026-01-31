/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:30:37 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 17:27:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// get max bits needed
static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (size > 0)
	{
		size >>= 1;
		bits++;
	}
	return (bits);
}

// Radix sort
void	radix_sort(t_stack **stk_a, t_stack **stk_b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = get_stack_size(*stk_a);
	max_bits = get_max_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stk_a)->index >> bit) & 1) == 0)
				push_to_b_op(stk_a, stk_b);
			else
				rotate_a_op(stk_a);
			i++;
		}
		while (*stk_b)
			push_to_a_op(stk_a, stk_b);
		bit++;
	}
}

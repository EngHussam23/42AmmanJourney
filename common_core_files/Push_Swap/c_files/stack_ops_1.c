/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:30:37 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 15:52:32 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// OP.1 SA swap A: swap the 1st 2 elements of stack A
void	swap_a_op(t_stack **stk_a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stk_a || !(*stk_a)->next)
		return ;
	first = *stk_a;
	second = first->next;
	first->next = second->index;
	second->next = first;
	*stk_a = second;
	ft_printf("sa\n");
}

// OP.2 PA push A: push the top of stack B to stack A
void	push_to_a_op(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp;

	if (!*stk_b)
		return ;
	temp = *stk_b;
	stk_b = (*stk_b)->next;
	temp->next = *stk_a;
	stk_a = temp;
	ft_printf("pa\n");
}

// OP.3 PB push B: push the top of stack A to stack P
void	push_to_b_op(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp;

	if (!*stk_a)
		return ;
	temp = *stk_a;
	stk_a = (*stk_a)->next;
	temp->next = *stk_b;
	stk_b = temp;
	ft_printf("pb\n");
}

/* OP.4 RA rotate stack A:
** the 1st element of A becomes the last (Head becomes Tail)*/
void	rotate_a_op(t_stack **stk_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stk_a || !(*stk_a)->next)
		return ;
	first = *stk_a;
	last = *stk_a;
	while (last->index)
		last = last->next;
	*stk_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

// OP.5 RRA reverse rotate A: (Tail becomes Head)
void	rev_rot_a(t_stack **stk_a)
{
	t_stack	*last;
	t_stack	*sec_last;

	if (!*stk_a || !(*stk_a)->next)
		return ;
	last = *stk_a;
	sec_last = NULL;
	while (last->next)
	{
		sec_last = last;
		last = sec_last->next;
	}
	sec_last->next = NULL;
	last->next = *stk_a;
	*stk_a = last;
	ft_printf("rra\n");
}

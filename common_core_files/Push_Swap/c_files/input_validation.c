/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:29:55 by halragga          #+#    #+#             */
/*   Updated: 2026/02/06 19:33:30 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Validation flow:
// 1. Character validation (done)
// 		a- skip beginning spaces
//		b- check if it's an empty string
//		b- chack the characters combinations in the input if valid
//				{signs, numbers, spaces} else is invalid
// 2. Parse into integers (done)
// 3. Check for duplicates (current...)
// 4. Store in a data structure (stack/array)
void	validate_args(int c, char **t)
{
	int	row;
	int	col;

	row = 1;
	while (row < c)
	{
		col = 0;
		while (is_space(t[row][col]))
			col++;
		if (!t[row][col])
			ft_exit_error(1);
		while (t[row][col])
		{
			if ((!ft_isdigit(t[row][col]) && !is_space(t[row][col])
			&& !is_sign(t[row][col])) || (is_sign(t[row][col])
			&& (!ft_isdigit(t[row][col + 1]) ||
			(col > 0 && ft_isdigit(t[row][col - 1])))))
				ft_exit_error(2);
			col++;
		}
		row++;
	}
}

void	check_dups(t_stack **stk)
{
	t_stack	*crnt;
	t_stack	*chkr;

	crnt = *stk;
	while (crnt)
	{
		chkr = crnt->next;
		while (chkr)
		{
			if (crnt->value == chkr->value)
			{
				free_stack(stk);
				ft_exit_error(6);
			}
			chkr = chkr->next;
		}
		crnt = crnt->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:47:04 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 18:33:47 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	if (argc < 2)
		return (0);
	validate_args(argc, argv);
	stk_a = parser_main(argc, argv);
	check_dups(&stk_a);
	if (is_sorted(stk_a))
	{
		free_stack(&stk_a);
		return (0);
	}
	stk_b = NULL;
	sort_stack(&stk_a, &stk_b);
	free_stack(&stk_a);
	return (0);
}

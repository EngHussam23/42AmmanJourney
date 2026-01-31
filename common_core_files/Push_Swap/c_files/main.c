/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:47:04 by halragga          #+#    #+#             */
/*   Updated: 2026/01/31 12:36:14 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stk_a;

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
	free_stack(&stk_a);
	return (0);
}

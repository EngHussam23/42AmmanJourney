/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:21:21 by halragga          #+#    #+#             */
/*   Updated: 2026/01/30 23:42:01 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	parse_input(t_stack **stk, char *argv)
{
	char	**numbers;
	int		i;

	numbers = ft_split(argv, ' ');
	if (!numbers)
		ft_exit_error(3);
	i = 0;
	while (numbers[i])
	{
		add_to_stack(stk, parse_number(numbers[i]));
		free(numbers[i]);
		i++;
	}
}

t_stack	parser_main(int argc, char **argv)
{
	t_stack	*stk_a;
	int		i;

	stk_a = NULL;
	i = 1;
	while (i < argc)
	{
		parse_input(&stk_a, argv[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:21:21 by halragga          #+#    #+#             */
/*   Updated: 2026/02/06 19:54:27 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//I used long to store the value in case it exceeds the integer limits, and to
// able to check it.
void	parse_input(t_stack **stk, char *argv)
{
	char	**numbers;
	int		i;
	long	num;

	numbers = ft_split(argv, ' ');
	if (!numbers)
		ft_exit_error(3);
	i = 0;
	while (numbers[i])
	{
		num = ft_atol(numbers[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free(numbers[i]);
			free(numbers);
			ft_exit_error(4);
		}
		add_to_stack(stk, (int)num);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

t_stack	*parser_main(int argc, char **argv)
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
	return (stk_a);
}

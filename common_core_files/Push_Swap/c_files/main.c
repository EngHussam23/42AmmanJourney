/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:47:04 by halragga          #+#    #+#             */
/*   Updated: 2026/01/29 19:57:30 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static void	validate_args(int argc, char **argv)
{
	int	row;
	int	col;

	row = 1;
	while (row < argc)
	{
		col = 0;
		while (argv[row][col] == '\0' || is_space(argv[row][col]))
		{
			if (argv[row][col] == '\0')
				ft_printf("Error");//fix
			col++;
		}
		while (argv[row][col])
		{
			if ((!ft_isdigit(argv[row][col]) && !is_space(argv[row][col])
				&& !is_sign(argv[row][col])) || (is_sign(argv[row][col])
				&& (!ft_isdigit(argv[row][col + 1])
				|| (col > 0 && ft_isdigit(argv[row][col - 1])))))
				ft_printf("Error");//fix
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		validate_args(argc, argv);
}

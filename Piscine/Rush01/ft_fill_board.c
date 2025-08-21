/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:31:47 by halragga          #+#    #+#             */
/*   Updated: 2025/01/11 12:31:49 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_fill_board(int **table, int size, int *clues)
{
	int	row;
	int	col;
	
	row = 0;
	while (row < size)//Printing
	{
		col = 0;
		while (col < size)
		{
			table[row][col] = 4;
			col++;
		}
		row++;
	}
	row = 0;
	while (row < size)//Printing
	{
		col = 0;
		while (col < size)
		{
			write(1, &table[row][col], 1);
			col++;
		}
		while (col < size - 1)
		{
			write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

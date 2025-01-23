/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:57:59 by halragga          #+#    #+#             */
/*   Updated: 2025/01/03 17:56:55 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int width, int hight);

void	print_line(int width);

void	print_col(int height);

void	print_col(int height)
{
	int	x;
	
	x = 0;
	while (x < height)
	{
		write(1, "B\n", 1);
	}
}

void	print_line(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		write(1, "A", 1);
		while (i < width - 2)
		{
			write(1, "B", 1);
		}
		write(1, "c", 1);
	}
}

void	rush(int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= width)
	{
		print_line(width);
		if (height != 1)
		{
			print_col(height);
		}
		else
		{
			print_line(width);
		}
		print_line(width);
	}
}

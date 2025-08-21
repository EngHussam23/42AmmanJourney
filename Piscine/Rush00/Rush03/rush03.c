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

void	ft_putchar(char character);

void	print_inner(int width, int height)
{
	int	y;

	y = 0;
	if (width > 1)
	{
		ft_putchar('A');
		while (y < width - 2)
		{
			ft_putchar(' ');
			y++;
		}
		ft_putchar('B');
		ft_putchar('\n');
		y = 0;
	}
	else
	{
		while (y < height)
		{
			ft_putchar('C');
			ft_putchar('\n');
			y++;
		}
	}
}

void	print_line(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		ft_putchar('A');
		i++;
		while (i - 1 < width - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('C');
		i++;
		ft_putchar('\n');
		i++;
	}
}

void	print_shape(int width, int height)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		print_line(width);
		i++;
		print_inner(width, height);
		print_line(width);
		i++;
	}
}

void	print_point(void)
{
	ft_putchar('A');
}

void	rush(int width, int height)
{	
	if (width == 1)
	{
		if (height > 1)
			print_inner(width, height);
		else if (height == 1)
			print_point();
	}
	else if (height == 1)
	{
		if (width > 1)
			print_line(width);
		else if (width == 1)
			print_point();
	}
	else if (height > 1 && width > 1)
	{
		print_shape(width, height);
	}
	else
		write(1, "Width / height is either zero or less", 38);
}

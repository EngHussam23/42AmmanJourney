/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2025/12/18 18:37:37 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	show_guide(void)
{
	ft_printf("\nUsage:\n\n");
	ft_printf("Mandelbrot:\n");
	ft_printf("./fractol mandelbrot\n\n");
	ft_printf("Julia:\n");
	ft_printf("./fractol julia <real> <imaginary>\n\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc < 2 || argc > 4)
		show_guide();
	else
		open_window(argv);
	return (0);
}

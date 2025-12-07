/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2025/12/07 12:51:12 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	validate_args(int argc, char **argv)
{
	if (argc < 2 || argc == 3 || argc > 4)
	{
		ft_printf("#############\n# Opseyyyy! #\n#############\n\n");
		ft_printf("Usage:\n");
		ft_printf("Mandelbrot:\n./fractol mandelbrot\n\n");
		ft_printf("Julia:\n./fractol julia <real> <imaginary>\n\n");
		ft_printf("Examples:\n");
		ft_printf("./fractol mandelbrot\n");
		ft_printf("./fractol julia -0.7 0.27015\n\n#############\n");
	}
	else if (argc == 2 && argv[1] == "mandelbrot")
		ft_printf("");
}

int	main(int argc, char **argv)
{
	validate_args(argc, argv);
	return (0);
}

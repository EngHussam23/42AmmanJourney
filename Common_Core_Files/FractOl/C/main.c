/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2025/12/21 19:48:45 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	valid_fractal(char *fract_name)
{
	if (!ft_strncmp(fract_name, "mandelbrot", 10))
		return (1);
	else if (!ft_strncmp(fract_name, "julia", 5))
		return (1);
	else
		return (0);
}

static void	show_guide(void)
{
	ft_printf("\nUsage:\n\n");
	ft_printf("Mandelbrot:\n");
	ft_printf("./fractol mandelbrot\n\n");
	ft_printf("Julia:\n");
	ft_printf("The default value is:\n");
	ft_printf("./fractol julia -0.7 0.27015\n");
	ft_printf("./fractol julia <real> <imaginary>\n\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 4 || !valid_fractal(argv[1]))
	{
		show_guide();
		return (1);
	}
	open_window(argv);
	return (0);
}

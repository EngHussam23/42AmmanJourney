/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2025/12/07 19:05:30 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

// static void	validate_args(int argc, char **argv)
// {
// 	if (argc < 2 || argc == 3 || argc > 4)
// 	{
// 		ft_printf("#############\n# Opseyyyy! #\n#############\n\n");
// 		ft_printf("Usage:\n");
// 		ft_printf("Mandelbrot:\n./fractol mandelbrot\n\n");
// 		ft_printf("Julia:\n./fractol julia <real> <imaginary>\n\n");
// 		ft_printf("Examples:\n");
// 		ft_printf("./fractol mandelbrot\n");
// 		ft_printf("./fractol julia -0.7 0.27015\n\n#############\n");
// 	}
// 	else if (argc == 2 && argv[1] == "mandelbrot")
// 		ft_printf("");
// }

/*int argc, char **argv*/
int	main(void)
{
	t_fractal	fract;

	init_fractal(&fract);
	fill_window(&fract, 0xFF00FF);
	mlx_key_hook(fract.win, (void *)handle_keypress, &fract);
	mlx_hook(fract.win, 17, 0, (void *)handle_close, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
// validate_args(argc, argv);

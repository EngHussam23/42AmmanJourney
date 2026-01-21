/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2026/01/15 14:12:37 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	valid_fractal(char *fract_name)
{
	if (!ft_strcmp(fract_name, "mandelbrot"))
		return (1);
	else if (!ft_strcmp(fract_name, "julia"))
		return (1);
	else if (!ft_strcmp(fract_name, "phoenix"))
		return (1);
	else
		return (0);
}

void	show_guide(void)
{
	ft_printf("\nUsage:\n\n");
	ft_printf("Mandelbrot:\n");
	ft_printf("./fractol mandelbrot\n\n");
	ft_printf("Julia:\n");
	ft_printf("The default value is:\n");
	ft_printf("./fractol julia -0.7 0.27015\n");
	ft_printf("./fractol julia <real> <imaginary>\n\n");
	ft_printf("\nBONUS!\n");
	ft_printf("Phoenix:\n");
	ft_printf("./fractol phoenix\n\n");
}

// mlx_destroy_image(data->mlx, data->img.img);
// mlx_destroy_window(data->mlx, data->win);
// mlx_destroy_display(data->mlx);
// free(data->mlx);
// (void)data;
/*t_mlx_data *data*/
static void	ft_exit(int code, char *msg, void *func(void))
{
	if (msg)
		ft_printf("\n%s", msg);
	if (func)
		func();
	exit(code);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc < 2 || argc > 4 || !valid_fractal(argv[1]))
		ft_exit(1, "Incorrect fractal name, check this \n", show_guide);
	if (open_window(&data, argv) != 0)
		ft_exit(2, "Err: failed to open the window", NULL);
	if (render_image(&data) != 0)
		ft_exit(3, "Unable to render the image", NULL);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
// ft_exit(&data, 0, NULL, NULL);

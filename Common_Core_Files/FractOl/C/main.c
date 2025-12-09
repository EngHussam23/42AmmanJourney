/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:49:45 by halragga          #+#    #+#             */
/*   Updated: 2025/12/09 19:51:31 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	print_usage(void)
{
	ft_printf("#############\n# Opseyyyy! #\n#############\n\n");
	ft_printf("Usage:\n");
	ft_printf("Mandelbrot:\n./fractol mandelbrot\n\n");
	ft_printf("Julia:\n./fractol julia <real> <imaginary>\n\n");
	ft_printf("Examples:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia -0.7 0.27015\n\n#############\n");
	exit(1);
}

static int	str_equal(const char *a, const char *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	if (len_a != len_b)
		return (0);
	return (ft_strncmp(a, b, len_b) == 0);
}

static void	start_fractal(t_fractal *f)
{
	init_fractal(f);
	render_fractal(f);
	mlx_key_hook(f->win, handle_keypress, f);
	mlx_hook(f->win, 17, 0, handle_close, f);
	mlx_loop(f->mlx);
}

static void	parse_args(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && str_equal(argv[1], "mandelbrot"))
		f->type = MANDELBROT;
	else if (argc == 4 && str_equal(argv[1], "julia"))
	{
		f->type = JULIA;
		f->julia_x = ft_atof(argv[2]);
		f->julia_y = ft_atof(argv[3]);
	}
	else
		print_usage();
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	parse_args(argc, argv, &f);
	start_fractal(&f);
	return (0);
}

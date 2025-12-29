/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:19:59 by halragga          #+#    #+#             */
/*   Updated: 2025/12/23 15:08:40 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	init_fract(t_mlx_data *data, char **argv)
{
	data->fract.clr_shift = 0;
	data->fract.julia_mode = 0;
	data->fract.name = argv[1];
	data->fract.zoom = 1.0;
	data->fract.offset_x = 0.0;
	data->fract.offset_y = 0.0;
	data->fract.max_itr = 100;
	if (!ft_strncmp(argv[1], "julia", 5) && argv[2] && argv[3])
	{
		data->fract.julia_c.re = ft_atof(argv[2]);
		data->fract.julia_c.im = ft_atof(argv[3]);
	}
	else if (!ft_strncmp(argv[1], "phoenix", 7))
	{
		data->fract.julia_c.re = 0.56667;
		data->fract.julia_c.im = -0.5;
	}
	else
	{
		data->fract.julia_c.re = -0.7;
		data->fract.julia_c.im = 0.27015;
	}
}

void	open_window(char **argv)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MLX window Test");
	data.img.img = NULL;
	init_fract(&data, argv);
	render_image(&data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_mouse_hook(data.win, mouse_handler, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:19:59 by halragga          #+#    #+#             */
/*   Updated: 2025/12/29 17:20:35 by halragga         ###   ########.fr       */
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

int	open_window(t_mlx_data *data, char **argv)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		return (2);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "MLX window Test");
	if (!(data->win))
		return (3);
	data->img.img = NULL;
	init_fract(data, argv);
	return (0);
}

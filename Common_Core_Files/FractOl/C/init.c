/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:19:59 by halragga          #+#    #+#             */
/*   Updated: 2025/12/18 18:56:29 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	open_window(char **argv)
{
	t_mlx_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MLX window Test");
	data.fract.name = argv[1];
	render_image(data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_loop(data.mlx);
}

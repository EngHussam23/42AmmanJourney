/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:10:08 by halragga          #+#    #+#             */
/*   Updated: 2025/12/22 15:16:03 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	render_image(t_mlx_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!ft_strncmp(data->fract.name, "mandelbrot", 10))
		mandelbrot(*data);
	else if (!ft_strncmp(data->fract.name, "julia", 5))
		julia(*data);
	else if (!ft_strncmp(data->fract.name, "phoenix", 7))
		phoenix(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

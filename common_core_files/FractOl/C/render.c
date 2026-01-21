/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:10:08 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 13:38:42 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	render_image(t_mlx_data *data)
{
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!ft_strcmp(data->fract.name, "mandelbrot"))
		mandelbrot(data);
	else if (!ft_strcmp(data->fract.name, "julia"))
		julia(data);
	else if (!ft_strcmp(data->fract.name, "phoenix"))
		phoenix(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:10:08 by halragga          #+#    #+#             */
/*   Updated: 2025/12/15 20:35:53 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	render_image(t_mlx_data data)
{
	char	*d_ad;
	int		pxl;
	int		x;
	int		y;

	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	d_ad = mlx_get_data_addr(data.img.img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	y = 0;
	x = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			pxl = (y * data.img.line_len) + (x * 4);
			d_ad[pxl + 0] = 0xF0;
			d_ad[pxl + 1] = 0x0F;
			d_ad[pxl + 2] = 0xF0;
			d_ad[pxl + 3] = 0x0F;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
}

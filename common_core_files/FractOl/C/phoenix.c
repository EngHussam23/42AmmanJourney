/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:47:26 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 15:04:17 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	calc(t_complex z, t_complex c, t_complex p, int max_itr)
{
	t_complex	z_prev;
	t_complex	temp;
	int			i;

	z_prev.re = 0;
	z_prev.im = 0;
	i = 0;
	while (i < max_itr)
	{
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		temp.re = z.re * z.re - z.im * z.im
			+ c.re + p.re * z_prev.re - p.im * z_prev.im;
		temp.im = 2 * z.re * z.im + c.im + p.re * z_prev.im + p.im * z_prev.re;
		z_prev = z;
		z = temp;
		i++;
	}
	return (i);
}

static void	set_pxl_clr(t_mlx_data *data, int x, int y, int itr)
{
	if (itr == data->fract.max_itr)
		put_pixel(data, x, y, 0x00000000);
	else
		put_pixel(data, x, y,
			colorize(itr, data->fract.max_itr, data->fract.clr_shift));
}

void	phoenix(t_mlx_data *data)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	p;

	c.re = 0.5667;
	c.im = 0.0;
	p.re = -0.5;
	p.im = 0.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->cmp.re = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data->fract.zoom
				+ data->fract.offset_y;
			data->cmp.im = (x - WIDTH / 2.0) * 4.0 / WIDTH * data->fract.zoom
				+ data->fract.offset_x;
			set_pxl_clr(data, x, y, calc(data->cmp, c, p, data->fract.max_itr));
			x++;
		}
		y++;
	}
}

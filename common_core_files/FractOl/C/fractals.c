/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:10:08 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 15:04:13 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	put_pixel(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->img.addr
			+ (y * data->img.line_len + x * (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static int	calc_mandel(t_complex cplx, int max_itr)
{
	t_complex	z;
	double		zr2;
	double		zi2;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < max_itr)
	{
		zr2 = z.re * z.re;
		zi2 = z.im * z.im;
		if (zr2 + zi2 > 4.0)
			return (i);
		z.im = 2 * z.re * z.im + cplx.im;
		z.re = zr2 - zi2 + cplx.re;
		i++;
	}
	return (i);
}

static int	calc_julia(t_complex z_cplx, t_complex c_cplx, int max_itr)
{
	double	zr2;
	double	zi2;
	int		i;

	i = 0;
	while (i < max_itr)
	{
		zr2 = z_cplx.re * z_cplx.re;
		zi2 = z_cplx.im * z_cplx.im;
		if (zr2 + zi2 > 4.0)
			return (i);
		z_cplx.im = 2 * z_cplx.re * z_cplx.im + c_cplx.im;
		z_cplx.re = zr2 - zi2 + c_cplx.re;
		i++;
	}
	return (i);
}

void	mandelbrot(t_mlx_data *data)
{
	int		x;
	int		y;
	int		itr;
	double	scale_x;
	double	scale_y;

	scale_x = 4.0 / WIDTH * data->fract.zoom;
	scale_y = 4.0 / WIDTH * data->fract.zoom;
	y = -1;
	while (++y < HEIGHT)
	{
		data->cmp.im = (y - HEIGHT / 2.0) * scale_y + data->fract.offset_y;
		x = -1;
		while (++x < WIDTH)
		{
			data->cmp.re = (x - WIDTH / 2.0) * scale_x + data->fract.offset_x;
			itr = calc_mandel(data->cmp, data->fract.max_itr);
			if (itr == data->fract.max_itr)
				put_pixel(data, x, y, 0x000000);
			else
				put_pixel(data, x, y,
					colorize(itr, data->fract.max_itr, data->fract.clr_shift));
		}
	}
}

void	julia(t_mlx_data *data)
{
	int		x;
	int		y;
	int		itr;
	double	scale_x;
	double	scale_y;

	scale_x = 4.0 / WIDTH * data->fract.zoom;
	scale_y = 4.0 / WIDTH * data->fract.zoom;
	y = -1;
	while (++y < HEIGHT)
	{
		data->cmp.im = (y - HEIGHT / 2.0) * scale_y + data->fract.offset_y;
		x = -1;
		while (++x < WIDTH)
		{
			data->cmp.re = (x - WIDTH / 2.0) * scale_x + data->fract.offset_x;
			itr = calc_julia(data->cmp, data->fract.julia_c,
					data->fract.max_itr);
			if (itr == data->fract.max_itr)
				put_pixel(data, x, y, 0x000000);
			else
				put_pixel(data, x, y,
					colorize(itr, data->fract.max_itr, data->fract.clr_shift));
		}
	}
}

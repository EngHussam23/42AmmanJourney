/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:10:08 by halragga          #+#    #+#             */
/*   Updated: 2025/12/21 15:58:00 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	put_pixel(t_mlx_data *data, int x, int y, int color)
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
	double		temp;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < max_itr)
	{
		if (((z.re * z.re) + (z.im * z.im)) > 4.0)
			return (i);
		temp = z.re * z.re - z.im * z.im + cplx.re;
		z.im = 2 * z.re * z.im + cplx.im;
		z.re = temp;
		i++;
	}
	return (i);
}

static int	calc_julia(t_complex z_cplx, t_complex c_cplx, int max_itr)
{
	double	temp;
	int		i;

	i = 0;
	while (i < max_itr)
	{
		if ((pow(z_cplx.re, 2) + pow(z_cplx.im, 2)) > 4.0)
			return (i);
		temp = pow(z_cplx.re, 2) - pow(z_cplx.im, 2) + c_cplx.re;
		z_cplx.im = 2 * z_cplx.re * z_cplx.im + c_cplx.im;
		z_cplx.re = temp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_mlx_data data)
{
	int	x;
	int	y;
	int	itr;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data.cmp.re = (x - WIDTH / 2.0) * 4.0 / WIDTH * data.fract.zoom
				+ data.fract.offset_x;
			data.cmp.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data.fract.zoom
				+ data.fract.offset_y;
			itr = calc_mandel(data.cmp, data.fract.max_itr);
			if (itr == data.fract.max_itr)
				put_pixel(&data, x, y, 0x000000);
			else
				put_pixel(&data, x, y, colorize(itr, data.fract.max_itr));
			x++;
		}
		y++;
	}
}

void	julia(t_mlx_data data)
{
	int	x;
	int	y;
	int	itr;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data.cmp.re = (x - WIDTH / 2.0) * 4.0 / WIDTH * data.fract.zoom
				+ data.fract.offset_x;
			data.cmp.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT * data.fract.zoom
				+ data.fract.offset_y;
			itr = calc_julia(data.cmp, data.fract.julia_c, data.fract.max_itr);
			if (itr == data.fract.max_itr)
				put_pixel(&data, x, y, 0x000000);
			else
				put_pixel(&data, x, y, colorize(itr, data.fract.max_itr));
			x++;
		}
		y++;
	}
}

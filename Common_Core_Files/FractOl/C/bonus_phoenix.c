/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_phoenix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:47:26 by halragga          #+#    #+#             */
/*   Updated: 2025/12/29 17:22:42 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	calc(t_complex z, t_complex c, int max_itr)
{
	t_complex	z_prev;
	double		temp;
	int			i;

	z_prev.re = 0;
	z_prev.im = 0;
	i = 0;
	while (i < max_itr)
	{
		if (((z.re * z.re) + (z.im * z.im)) > 4.0)
			return (i);
		temp = z.re * z.re - z.im * z.im + c.im * z_prev.re;
		z_prev.re = z.re;
		z_prev.im = z.im;
		z.im = 2 * z.re * z.im + c.im * z_prev.im;
		z.re = temp;
		i++;
	}
	return (i);
}

void	phoenix(t_mlx_data data)
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
			itr = calc(data.cmp, data.fract.julia_c, data.fract.max_itr);
			if (itr == data.fract.max_itr)
				put_pixel(&data, x, y, 0x00000000);
			else
				put_pixel(&data, x, y,
					colorize(itr, data.fract.max_itr, data.fract.clr_shift));
		}
	}
}

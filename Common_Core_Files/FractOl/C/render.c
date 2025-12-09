/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:00:00 by halragga          #+#    #+#             */
/*   Updated: 2025/12/09 20:16:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	map_pixel(int x, int y, double *cr, double *ci)
{
	*cr = (x - WIN_WIDTH / 2.0) * 4.0 / WIN_WIDTH;
	*ci = (y - WIN_HEIGHT / 2.0) * 4.0 / WIN_HEIGHT;
}

static int	calc_pixel(int x, int y, t_fractal *f)
{
	double	cr;
	double	ci;
	int		iter;

	map_pixel(x, y, &cr, &ci);
	cr = cr / f->zoom + f->offset_x;
	ci = ci / f->zoom + f->offset_y;
	if (f->type == MANDELBROT)
		iter = mandelbrot(cr, ci, f->max_iter);
	else
		iter = julia(cr, ci, f);
	return (get_color(iter, f->max_iter, f->color));
}

void	render_fractal(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(&f->img, x, y, calc_pixel(x, y, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

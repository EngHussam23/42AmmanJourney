/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:12 by halragga          #+#    #+#             */
/*   Updated: 2025/12/07 19:26:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	init_fractal(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->win = mlx_new_window(fract->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-Ol");
	if (!fract->win)
		exit(1);
	fract->img.img = mlx_new_image(fract->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!fract->img.img)
		exit(1);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
}

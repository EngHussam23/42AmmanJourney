/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:21:07 by halragga          #+#    #+#             */
/*   Updated: 2025/12/21 19:56:01 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	close_window(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_mlx_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		data->fract.zoom *= 0.9;
		data->fract.max_itr += 5;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->fract.zoom *= 1.1;
		if (data->fract.max_itr > 20)
			data->fract.max_itr -= 5;
	}
	render_image(data);
	return (0);
}

static void	handle_pan(int keycode, t_mlx_data *data)
{
	double	move;

	move = 1.0 * data->fract.zoom;
	if (keycode == LEFT_KEY)
		data->fract.offset_x -= move;
	else if (keycode == RIGHT_KEY)
		data->fract.offset_x += move;
	else if (keycode == UP_KEY)
		data->fract.offset_y -= move;
	else if (keycode == DOWN_KEY)
		data->fract.offset_y += move;
}

int	key_handler(int keycode, void *params)
{
	t_mlx_data	*vars;

	vars = (t_mlx_data *)params;
	ft_printf("Key Code: %d\n", keycode);
	if (keycode == ESC_KEY)
		close_window(vars);
	else if (keycode == LEFT_KEY || keycode == UP_KEY
		|| keycode == RIGHT_KEY || keycode == DOWN_KEY)
	{
		handle_pan(keycode, vars);
		render_image(vars);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:21:07 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 15:19:27 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mouse_move(int x, int y, t_mlx_data *data)
{
	static int	frame_count = 0;

	if (data->fract.julia_mode && !ft_strncmp(data->fract.name, "julia", 5))
	{
		data->fract.julia_c.re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		data->fract.julia_c.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
		if (frame_count++ % 5 == 0)
			render_image(data);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y, t_mlx_data *data)
{
	double	zoom_fact;

	if (button == MOUSE_SCROLL_UP)
	{
		zoom_fact = 0.9;
		data->fract.offset_x += (x - WIDTH / 2.0) * 4.0 / WIDTH
			* data->fract.zoom * (1 - zoom_fact);
		data->fract.offset_y += (y - HEIGHT / 2.0) * 4.0 / HEIGHT
			* data->fract.zoom * (1 - zoom_fact);
		data->fract.zoom *= zoom_fact;
		if (data->fract.max_itr < 100)
			data->fract.max_itr += 2;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		zoom_fact = 1.1;
		data->fract.zoom *= zoom_fact;
		if (data->fract.max_itr > 20)
			data->fract.max_itr -= 2;
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
	if (keycode == ESC_KEY)
		mlx_loop_end(vars->mlx);
	else if (keycode == LEFT_KEY || keycode == UP_KEY
		|| keycode == RIGHT_KEY || keycode == DOWN_KEY)
	{
		handle_pan(keycode, vars);
	}
	else if (keycode == C_KEY)
		vars->fract.clr_shift += 42;
	else if (keycode == R_KEY)
		vars->fract.julia_mode = !vars->fract.julia_mode;
	else if (keycode == PLUS_KEY)
		vars->fract.max_itr += 10;
	else if (keycode == MINUS_KEY)
	{
		if (vars->fract.max_itr > 10)
			vars->fract.max_itr -= 10;
	}
	render_image(vars);
	return (0);
}

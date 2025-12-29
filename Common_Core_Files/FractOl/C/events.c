/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:21:07 by halragga          #+#    #+#             */
/*   Updated: 2025/12/22 14:36:24 by halragga         ###   ########.fr       */
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

int	mouse_move(int x, int y, t_mlx_data *data)
{
	if (data->fract.julia_mode && !ft_strncmp(data->fract.name, "julia", 5))
	{
		data->fract.julia_c.re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		data->fract.julia_c.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
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
		data->fract.max_itr += 5;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		zoom_fact = 1.1;
		data->fract.zoom *= zoom_fact;
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
	if (keycode == ESC_KEY)
		close_window(vars);
	else if (keycode == LEFT_KEY || keycode == UP_KEY
		|| keycode == RIGHT_KEY || keycode == DOWN_KEY)
	{
		handle_pan(keycode, vars);
		render_image(vars);
	}
	else if (keycode == C_KEY)
	{
		vars->fract.clr_shift += 42;
		render_image(vars);
	}
	else if (keycode == R_KEY)
	{
		vars->fract.julia_mode = !vars->fract.julia_mode;
		if (vars->fract.julia_mode)
			ft_printf("Julia mouse mode: ON\n");
		else
			ft_printf("Julia mouse mode: OFF\n");
	}
	return (0);
}

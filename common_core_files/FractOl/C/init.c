/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:19:59 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 20:20:26 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	is_valid_double(char *str)
{
	int	sign_count;
	int	dot_count;
	int	i;

	if (!str)
		return (0);
	sign_count = 0;
	dot_count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i])
			&& str[i] != '.'
			&& str[i] != '-'
			&& str[i] != '+')
			return (0);
		if (str[i] == '.' && dot_count++)
			return (0);
		if ((str[i] == '+' || str[i] == '-') && sign_count++)
			return (0);
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_fract(t_mlx_data *data, int argc, char **argv)
{
	data->fract.clr_shift = 0;
	data->fract.julia_mode = 0;
	data->fract.name = argv[1];
	data->fract.zoom = 1.0;
	data->fract.offset_x = 0.0;
	data->fract.offset_y = 0.0;
	data->fract.max_itr = 30;
	if (!ft_strcmp(argv[1], "julia"))
	{
		if (is_valid_double(argv[2]) && is_valid_double(argv[3]))
		{
			data->fract.julia_c.re = ft_atof(argv[2]);
			data->fract.julia_c.im = ft_atof(argv[3]);
			return (0);
		}
		return (1);
	}
	if (argc != 2)
		return (2);
	if (!ft_strcmp(argv[1], "phoenix"))
	{
		data->fract.julia_c.re = 0.56667;
		data->fract.julia_c.im = -0.5;
	}
	return (0);
}

int	open_window(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		return (4);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "MLX window Test");
	if (!(data->win))
		return (5);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!(data->img.img))
		return (6);
	return (0);
}

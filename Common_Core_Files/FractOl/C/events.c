/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:21:07 by halragga          #+#    #+#             */
/*   Updated: 2025/12/14 15:22:37 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	key_handler(int keycode, void *params)
{
	t_mlx_data	*vars;

	vars = (t_mlx_data *)params;
	ft_printf("Key Code: %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	//else if when needed (for the other keys)
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:06:27 by halragga          #+#    #+#             */
/*   Updated: 2025/12/21 15:26:13 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	colorize(int itr, int max_itr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)itr / (double)max_itr;
	r = (int)(9 *(1 - t) * pow(t, 3) * 120);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 10);
	b = (int)(8.5 * pow((1 - t), 3) * t * 180 + t * 40);
	return ((r << 16) | (g << 8) | b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:06:27 by halragga          #+#    #+#             */
/*   Updated: 2025/12/22 13:49:24 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	colorize(int itr, int max_itr, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)itr / (double)max_itr;
	r = (int)(9 *(1 - t) * t * t * t * 120 + t * 60 + shift) % 256;
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 10 + shift / 2) % 256;
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 180
			+ t * 40 + shift / 3) % 256;
	return ((r << 16) | (g << 8) | b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:24:15 by halragga          #+#    #+#             */
/*   Updated: 2025/12/09 20:02:12 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	clr_fire(int itr, int max_itr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (itr == max_itr)
		return (0x000000);
	t = (double)itr / max_itr;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 + pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static int	clr_ocean(int itr, int max_itr)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (itr == max_itr)
		return (0x000000);
	t = (double)itr / max_itr;
	r = (int)(t * 80);
	g = (int)(t * 120 + 50 * sin(t * 3.14159));
	b = (int)(180 + 75 * sin(t * 3.14159 * 2));
	return ((r << 16) | (g << 8) | b);
}

static int	clr_electric(int iter, int max_iter)
{
	double	t;
	int		r;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(255 * sin(t * 3.14159));
	b = (int)(255 * cos(t * 3.14159 * 0.5));
	return ((r << 16) | (50 << 8) | b);
}

int	get_color(int iter, int max_iter, int scheme)
{
	if (scheme == 0)
		return (clr_fire(iter, max_iter));
	else if (scheme == 1)
		return (clr_ocean(iter, max_iter));
	else
		return (clr_electric(iter, max_iter));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:24:15 by halragga          #+#    #+#             */
/*   Updated: 2025/12/09 20:00:11 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static double	ft_atof_decimal(const char *str, double result, int sign)
{
	double	divisor;

	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (result * sign);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		return (ft_atof_decimal(str + 1, result, sign));
	return (result * sign);
}

int	mandelbrot_fract(double c_real, double c_img, int max_itr)
{
	double	z_real;
	double	z_img;
	int		i;

	z_real = 0;
	z_img = 0;
	i = 0;
	while (i < max_itr)
	{
		if ((z_img * z_img + z_img * z_real) > 4.0)
			return (i);
		z_real = 2 * z_real * z_img + c_img;
		z_img = z_real * z_real - z_img * z_img + c_real;
		i++;
	}
	return (max_itr);
}

int	julia_fract(double z_real, double z_img, t_fractal *fr)
{
	int	i;

	i = 0;
	while (i < fr->max_iter)
	{
		if ((z_real * z_real + z_img * z_img) > 4.0)
			return (i);
		z_img = 2 * z_real * z_img + fr->julia_y;
		z_real = z_real * z_real - z_img * z_img + fr->julia_x;
		i++;
	}
	return (fr->max_iter);
}

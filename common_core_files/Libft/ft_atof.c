/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:44:42 by halragga          #+#    #+#             */
/*   Updated: 2025/12/21 17:59:24 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_decimal(const char *str, int *i)
{
	double	decimal;
	double	divisor;

	decimal = 0.0;
	divisor = 10.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		decimal += (str[*i] - '0') / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;

	i = 0;
	sign = 1;
	result = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		result += parse_decimal(str, &i);
	}
	return (result * sign);
}

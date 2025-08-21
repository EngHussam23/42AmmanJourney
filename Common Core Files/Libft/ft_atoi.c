/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:38:48 by halragga          #+#    #+#             */
/*   Updated: 2025/08/21 11:24:45 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *ptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (ft_isdigit(*ptr))
	{
		result = result * 10 + (*ptr - 48);
		ptr++;
	}
	return (result * sign);
}
/*int	main (int argc, char **argv)
{
	if (argc > 2)
		printf("Too many ARGUMENTS!!!\n");
	else if (argc < 2)
		printf("Missing ARGUMENT!!!\n");
	else
	{
		printf("Standard: %d\n", atoi(argv[1]));
		printf("Reproduced: %d\n", ft_atoi(argv[1]));
	}
}*/

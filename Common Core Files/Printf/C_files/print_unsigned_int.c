/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:23:04 by halragga          #+#    #+#             */
/*   Updated: 2025/09/07 19:05:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	print_unsigned_int(unsigned int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += print_unsigned_int(n / 10, fd);
	c = '0' + (n % 10);
	ft_putchar_fd(c, fd);
	count++;
	return (count);
}

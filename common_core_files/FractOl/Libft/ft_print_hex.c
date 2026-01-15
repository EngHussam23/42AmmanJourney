/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:16 by halragga          #+#    #+#             */
/*   Updated: 2025/09/22 14:28:46 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_and_write(char c, unsigned int value, int count, int fd)
{
	if (value >= 16)
		count = convert_and_write(c, value / 16, count, fd);
	if (value % 16 < 10)
		count = ft_write_char('0' + (value % 16), fd, count);
	else if (value % 16 >= 10)
		count = ft_write_char(c + ((value % 16) - 10), fd, count);
	return (count);
}

int	ft_print_hex(char str_fmt, unsigned int value, int count, int fd)
{
	char	c;

	c = '0';
	if (str_fmt == 'x')
		c = 'a';
	else
		c = 'A';
	if (value == 0)
		count += write(fd, "0", 1);
	else
		count = convert_and_write(c, value, count, fd);
	return (count);
}

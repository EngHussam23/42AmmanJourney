/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:42:53 by halragga          #+#    #+#             */
/*   Updated: 2025/09/10 17:28:02 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int	convert_and_write(uintptr_t ptr, int count, int fd)
{
	if (address == 0)
	{
		write(fd, "0", 1);
		return (count + 1);
	}
	while (address > 0)
	{
		
	}
	return (count);
}

/*
	while (address > 0)
	{
		if (address % 16 < 10)
			*hex_addr = '0' + (address % 16);
		else
			*hex_addr = 'a' + ((address % 16) - 10);
		write(fd, hex_addr++, 1);
		address /= 16;
		count++;
	}
*/

int	print_void_ptr(void *ptr, int fd)
{
	uintptr_t	address;
	int			count;
	char		*hex_addr[20];

	count = 0;
	address = (uintptr_t)ptr;
	write(fd, "0x", 2);
	count += 2;
	convert_and_write(address, count, fd);
	return (count);
}

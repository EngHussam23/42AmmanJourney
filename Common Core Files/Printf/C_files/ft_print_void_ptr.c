/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_void_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:42:53 by halragga          #+#    #+#             */
/*   Updated: 2025/09/08 18:44:05 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	print_void_ptr(void *ptr, int fd)
{
	uintptr_t	address;
	int			count;
	char		*hex_addr;

	count = 0;
	address = (uintptr_t)ptr;
	hex_addr = "";
	write(fd, "0x", 2);
	count += 2;
	if (address == 0)
	{
		write(fd, "0", 1);
		return (count + 1);
	}
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
	return (count);
}

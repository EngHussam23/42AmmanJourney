/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:42:53 by halragga          #+#    #+#             */
/*   Updated: 2025/09/10 18:49:04 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int	convert_and_write(uintptr_t ptr, int count, int fd)
{
	while (ptr > 0)
	{
		convert_and_write(ptr / 16, count, fd);
		if (ptr % 16 < 10)
			ft_putchar_fd('0' + (ptr % 16), fd);
		else
			ft_putchar_fd('a' + ((ptr % 16) - 10), fd);
		count++;
		break;
	}
	return (count);
}

int	print_void_ptr(void* ptr, int fd)
{
	uintptr_t	address;
	int			count;

	count = 0;
	address = (uintptr_t)ptr;
	write(fd, "0x", 2);
	count += 2;
	if (ptr == 0)
	{
		write(fd, "0", 1);
		return (count + 1);
	}
	else
		convert_and_write(address, count, fd);
	return (count);
}

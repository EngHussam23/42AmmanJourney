/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:42:53 by halragga          #+#    #+#             */
/*   Updated: 2025/09/13 18:07:40 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	convert_and_write(uintptr_t ptr, int fd, int count)
{
	if (ptr % 16 < 10)
		count = ft_write_char('0' + (ptr % 16), fd, count);
	else if (ptr % 16 >= 10)
		count = ft_write_char('a' + ((ptr % 16) - 10), fd, count);
	else
		convert_and_write(ptr / 16, count, fd);
	count++;
	return (count);
}

int	ft_print_void_ptr(void *ptr, int fd)
{
	uintptr_t	address;
	int			count;

	count = 0;
	address = (uintptr_t)ptr;
	count += write(fd, "0x", 2);
	if (!ptr)
		count += write(fd, "0", 1);
	else
		count = convert_and_write(address, count, fd);
	return (count);
}

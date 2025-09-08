/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:40:38 by halragga          #+#    #+#             */
/*   Updated: 2025/09/08 18:45:45 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header_files/libft_printf.h"

// ToDo:
/*
	1- print void pointers in hexadecimal (base 16)
	2- print numbers in small case hexadecimal (base 16)
	3- print numbers in capital case hexadecimal (base 16)
*/

static int	print_unsigned_int(unsigned int n, int fd)
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

static int	find_format(const char *str_fmt, va_list args)
{
	int	count;

	count = 0;
	if (*str_fmt == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str_fmt == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str_fmt == 'd' || *str_fmt == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str_fmt == 'u')
		count += print_unsigned_int(va_arg(args, unsigned int), 1);
	else if (*str_fmt == 'p')
		print_void_ptr(va_arg(args, void *), 1);
	else if (*str_fmt == 'x' || *str_fmt == 'X')
		write(1, str_fmt, 1);
	else if (*str_fmt == '%')
		write(1, str_fmt, 1);
	return (count);
}

int	ft_printf(const char *str_fmt, ...)
{
	int		count;
	va_list	args;

	va_start(args, str_fmt);
	count = 0;
	while (*str_fmt)
	{
		if (*str_fmt == '%')
		{
			str_fmt++;
			find_format(str_fmt, args);
			str_fmt++;
		}
		if (*str_fmt)
		{
			write(1, str_fmt, 1);
			count++;
			str_fmt++;
		}
	}
	va_end(args);
	return (count);
}

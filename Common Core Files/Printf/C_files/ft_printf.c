/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:40:38 by halragga          #+#    #+#             */
/*   Updated: 2025/09/13 18:17:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	find_format(const char str_fmt, va_list args, int count)
{
	if (str_fmt == 'c')
		count = ft_write_char(va_arg(args, int), 1, count);
	else if (str_fmt == 's')
		count = ft_write_str(va_arg(args, char *), 1, count);
	else if (str_fmt == 'd' || str_fmt == 'i')
		count = ft_write_nbr(va_arg(args, int), 1, count);
	else if (str_fmt == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int), 1);
	else if (str_fmt == 'p')
		count += ft_print_void_ptr(va_arg(args, void *), 1);
	else if (str_fmt == 'x' || str_fmt == 'X')
		count = ft_print_hex(str_fmt, va_arg(args, unsigned int), count, 1);
	else if (str_fmt == '%')
		count += write(1, &str_fmt, 1);
	else
		return (0);
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
			count = find_format(*str_fmt, args, count);
			str_fmt++;
		}
		else if (*str_fmt)
		{
			count += write(1, str_fmt, 1);
			str_fmt++;
		}
	}
	va_end(args);
	return (count);
}

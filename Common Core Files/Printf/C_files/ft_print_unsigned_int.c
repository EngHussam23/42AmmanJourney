/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:55:46 by hussam            #+#    #+#             */
/*   Updated: 2025/09/13 12:23:43 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned_int(unsigned int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned_int(n / 10, fd);
	c = '0' + (n % 10);
	ft_putchar_fd(c, fd);
	count++;
	return (count);
}

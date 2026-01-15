/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:58:49 by hussam            #+#    #+#             */
/*   Updated: 2025/09/13 12:29:12 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_str(char *s, int fd, int count)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (count + 6);
	}
	while (*s)
	{
		write(fd, s, 1);
		count++;
		s++;
	}
	return (count);
}

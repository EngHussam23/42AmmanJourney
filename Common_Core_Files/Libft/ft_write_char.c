/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:58:49 by hussam            #+#    #+#             */
/*   Updated: 2025/09/22 14:29:35 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

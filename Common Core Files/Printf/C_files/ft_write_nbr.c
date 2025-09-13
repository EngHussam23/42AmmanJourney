/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:07:47 by hussam            #+#    #+#             */
/*   Updated: 2025/09/13 13:55:26 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_nbr(int n, int fd, int count)
{
	char	*ptr;

	ptr = ft_itoa(n);
	count += ft_strlen(ptr);
	ft_putstr_fd(ptr, fd);
	free(ptr);
	return (count);
}

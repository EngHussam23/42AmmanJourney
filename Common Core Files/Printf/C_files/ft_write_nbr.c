/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:07:47 by hussam            #+#    #+#             */
/*   Updated: 2025/09/13 12:28:12 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_nbr(int n, int fd, int count)
{
	count += ft_strlen(ft_itoa(n));
	ft_putstr_fd(ft_itoa(n), fd);
	return (count);
}

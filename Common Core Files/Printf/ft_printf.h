/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:57:05 by halragga          #+#    #+#             */
/*   Updated: 2025/09/13 12:21:54 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_void_ptr(void *ptr, int fd);
int	ft_print_hex(char str_fmt, unsigned int x, int count, int fd);
int	ft_print_unsigned_int(unsigned int n, int fd);
int	ft_write_char(char c, int fd, int count);
int	ft_write_str(char *str, int fd, int count);
int	ft_write_nbr(int n, int fd, int count);

#endif

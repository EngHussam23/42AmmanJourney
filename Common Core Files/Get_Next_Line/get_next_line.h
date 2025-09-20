/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:57:05 by halragga          #+#    #+#             */
/*   Updated: 2025/09/20 20:39:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_get_next_line(int fd);
char	*ft_strchr(const char* s, int c);
size_t	ft_strlcat(char* dst, const char* src, size_t dstsize);

#endif

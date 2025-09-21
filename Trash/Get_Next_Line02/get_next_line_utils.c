/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:04:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/21 17:13:56 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char* s, int c)
{
	while (*s != '\0')
	{
		if (!(*s >= 0 && *s <= 127))
			return (NULL);
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		srclen;
	size_t		dst_index;
	size_t		src_index;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst_index = ft_strlen(dst);
	src_index = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	else
	{
		while (src_index < srclen && dst_index < (dstsize - 1)
			&& src[src_index] != '\0')
			dst[dst_index++] = src[src_index++];
		dst[dst_index] = '\0';
	}
	return (srclen + dstlen);
}

size_t	ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

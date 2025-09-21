/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:31 by halragga          #+#    #+#             */
/*   Updated: 2025/08/31 18:45:56 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

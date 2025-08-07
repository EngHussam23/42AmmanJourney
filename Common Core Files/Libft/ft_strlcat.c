/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:31 by halragga          #+#    #+#             */
/*   Updated: 2025/08/07 14:18:20 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		srclen;
	size_t		spc;
	size_t		i;
	
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	spc = dstsize - dstlen;
	i = dstlen;
	if (spc == 0)
		return (srclen + dstlen);
	else
	{
		if (spc > src)
		
	}
}

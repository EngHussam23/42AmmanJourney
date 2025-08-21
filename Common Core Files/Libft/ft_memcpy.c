/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:58:01 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 20:18:53 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t cpysize)
{
	size_t			i;
	char			*cdest;
	const char		*csrc;

	i = 0;
	if ((!dest && !src) || cpysize == 0)
		return (dest);
	csrc = (const char *)src;
	cdest = (char *)dest;
	while (i < cpysize)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

/*int		main(void)
{
	memcpy("\0", "\0", 1);
	return (0);
}*/

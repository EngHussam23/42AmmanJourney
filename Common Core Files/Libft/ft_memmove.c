/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:42:51 by halragga          #+#    #+#             */
/*   Updated: 2025/08/27 23:42:43 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*reverse_fill(char *dest, const char *src, size_t mvsize)
{
	int	i;

	i = (int) mvsize - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t mvsize)
{
	const char		*csrc;
	char			*cdest;

	csrc = (const char *)src;
	cdest = (char *)dest;
	if (dest < src)
		return (ft_memcpy(cdest, csrc, mvsize));
	else if (dest > src)
		return (reverse_fill(cdest, csrc, mvsize));
	else
		return (cdest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:42:51 by halragga          #+#    #+#             */
/*   Updated: 2025/08/28 13:14:32 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

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
	size_t			i;

	csrc = (const char *)src;
	cdest = (char *)dest;
	i = 0;
	if (dest < src)
		return (ft_memcpy(cdest, csrc, mvsize));
	else if (dest > src)
		return (reverse_fill(cdest, csrc, mvsize));
	else
		return (cdest);
}
// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	printf("%s", (char *)memmove(str+9, str, 4));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:39:29 by halragga          #+#    #+#             */
/*   Updated: 2025/08/06 19:26:12 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <bsd/string.h>

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dstlen;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	dstlen = ft_strlen(dst);
	return (dstlen);
}

int	main(int argc, char *argv[])
{
	if (argc > 3)
		printf("Too many ARGUMENTS...\n");
	else if (argc < 3)
		printf("Missing ARGUMENTS...\n");
	else
	{
		printf("My Result: %zu\n", ft_strlcpy(argv[2], argv[1], 5));
		printf("Standard Result: %zu\n", strlcpy(argv[2], argv[1], 5));
	}
	return (0);
}

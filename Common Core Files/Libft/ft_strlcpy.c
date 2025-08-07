/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:39:29 by halragga          #+#    #+#             */
/*   Updated: 2025/08/07 12:13:12 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		srclen;

	i = 0;
	while (i < size-1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	srclen = ft_strlen(src);
	return (srclen);
}

int	main(int argc, char *argv[])
{
	if (argc > 3)
		printf("Too many ARGUMENTS...\n");
	else if (argc < 3)
		printf("Missing ARGUMENTS...\n");
	else
	{
		printf("Src length before: %zu\n\n", ft_strlen(argv[1]));
		printf("My Result: %zu\n\n", ft_strlcpy(argv[2], argv[1], 5));
		printf("Standard Result: %zu\n\n", strlcpy(argv[2], argv[1], 5));
		printf("Src length after: %zu\n", ft_strlen(argv[1]));
	}
	return (0);
}

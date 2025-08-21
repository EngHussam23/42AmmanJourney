/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:04 by halragga          #+#    #+#             */
/*   Updated: 2025/08/17 11:10:29 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*cs1;
	unsigned char			*cs2;
	size_t					i;

	i = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
/*int	main(int argc, char **argv)
{
	if (argc > 3)
		printf("Too many ARGUMENTS\n");
	else if (argc < 3)
		printf("Too many ARGUMENTS\n");
	else
	{
		printf("Standard result: %d\n", memcmp(argv[1], argv[2], 6));
		printf("My result: %d\n", ft_memcmp(argv[1], argv[2], 6));
	}
}*/

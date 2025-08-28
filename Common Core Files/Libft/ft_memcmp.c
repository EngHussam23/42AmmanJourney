/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:04 by halragga          #+#    #+#             */
/*   Updated: 2025/08/28 13:15:25 by halragga         ###   ########.fr       */
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

// int main(void)
// {
// 	char str1[] = "Hellzo, World!";
// 	char str2[] = "Hello, World!";
// 	printf("%d\n", ft_memcmp(str1, str2, 13));
// 	printf("%d\n", memcmp(str1, str2, 13));
// 	return (0);
// }

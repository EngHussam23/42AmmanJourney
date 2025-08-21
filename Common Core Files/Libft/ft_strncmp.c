/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:40 by halragga          #+#    #+#             */
/*   Updated: 2025/08/17 11:43:04 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
		i++;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	if (argc > 3)
		printf("Too many ARGUMENTS!!!!!!!!\n");
	else if (argc < 3)
		printf("Missing ARGUMENTS!!!!!!!!\n");
	else
	{
		printf("%d\n", strncmp(argv[1], argv[2], 4));
		printf("%d\n", ft_strncmp(argv[1], argv[2], 4));
	}
	return (0);
}*/

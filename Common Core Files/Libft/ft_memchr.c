/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:39:58 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 19:08:51 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char *) s;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return (cs + i);
		i++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	char	*std;
	char	*usrdeff;
	
	std = memchr(argv[1], argv[2][0], 2);
	usrdeff = ft_memchr(argv[1], argv[2][0], 2);
	if (argc > 3)
		printf("Too many ARGUMENTS!!!\n");
	else if (argc < 3)
		printf("Missing ARGUMENTS!!!\n");
	else
		{
			printf("Standard result: %s\n", std);
			printf("My result: %s\n", usrdeff);
		}
}*/

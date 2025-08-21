/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:58:01 by halragga          #+#    #+#             */
/*   Updated: 2025/08/06 11:30:07 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t cpysize)
{
	size_t			i;
	char			*cdest;
	const char		*csrc;

	i = 0;
	csrc = src;
	cdest = dest;
	while (i < cpysize)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

/*int		main(void)
{
	char	src[5];
	char	dest[10];
	int		i;
	
	//Source pointer
	src[0] = 'H';
	src[1] = 'e';
	src[2] = 'l';
	src[3] = 'l';
	src[4] = 'o';
	//Destination ppointer
	dest[0] = '0';
	dest[1] = '0';
	dest[2] = '0';
	dest[3] = '0';
	dest[4] = '0';
	dest[5] = 'W';
	dest[6] = 'o';
	dest[7] = 'r';
	dest[8] = 'l';
	dest[9] = 'd';
	i = 0;
	printf("Before\n");
	while (i < 10)
	{
		printf("%c", dest[i]);
		i++;
	}
	printf("\n\nAfter\n");
	ft_memcpy(dest, src, 5);
	i = 0;
	while (i < 10)
	{
		printf("%c", dest[i]);
		i++;
	}
	printf("\n");
	
	return (0);
}*/

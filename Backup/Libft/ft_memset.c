/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:45:59 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 18:54:28 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
// #include <string.h>

#include "libft.h"

void	*ft_memset(void *ptr, int fill, size_t size)
{
	char		*cptr;
	size_t		i;

	cptr = ptr;
	i = 0;
	while (i < size)
	{
		cptr[i] = fill;
		i++;
	}
	return (ptr);
}

/*
int	main(void)
{
	char		stdtst[10];
	char		usrtst[10];
	size_t		size;
	size_t		i;

	size = 10;
	i = 0;
	ft_memset(usrtst, 'y', size);
	memset(stdtst, 'x', size);
	while (i < size)
	{
		printf("%c, %c\n", stdtst[i], usrtst[i]);
		i++;
	}
	return (0);
}
*/

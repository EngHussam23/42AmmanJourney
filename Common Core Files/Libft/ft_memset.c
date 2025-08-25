/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:45:59 by halragga          #+#    #+#             */
/*   Updated: 2025/08/24 14:39:11 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

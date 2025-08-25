/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:26:48 by halragga          #+#    #+#             */
/*   Updated: 2025/08/25 13:22:42 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t	i;
	char	*cptr;

	i = 0;
	cptr = (char *)ptr;
	while (i < size)
	{
		cptr[i] = '\0';
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:46 by halragga          #+#    #+#             */
/*   Updated: 2025/08/24 16:40:43 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t length)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(small) == 0)
		return ((char *) big);
	while (i < length && big[i])
	{
		j = 0;
		while (small[j] && i + j < length)
		{
			if (big[i + j] == small[j])
				j++;
			else
				break ;
			if (j == ft_strlen(small))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

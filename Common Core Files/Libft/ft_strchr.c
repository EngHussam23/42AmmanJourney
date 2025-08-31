/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:19 by halragga          #+#    #+#             */
/*   Updated: 2025/08/31 11:13:41 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
		while (*s != '\0')
	{
		if (!ft_isascii(*s))
			return (NULL);
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char *) s);
	return (NULL);
}

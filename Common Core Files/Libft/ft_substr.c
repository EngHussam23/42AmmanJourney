/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:07:43 by halragga          #+#    #+#             */
/*   Updated: 2025/08/25 15:14:37 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*sub_s;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start < len)
		j = ft_strlen(s) - start;
	else if (ft_strlen(s) == len)
		j = ft_strlen(s);
	else
		j = len;
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	sub_s = malloc((j + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (i < j)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

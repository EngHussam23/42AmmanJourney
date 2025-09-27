/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:33 by halragga          #+#    #+#             */
/*   Updated: 2025/09/27 18:21:00 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_len(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

char	*join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1)
		s1 = str_duplicate("", 1);
	if (!s2)
		s2 = str_duplicate("", 1);
	result = malloc(get_len(s1) + get_len(s2) + 1);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*str_duplicate(const char *src, size_t size)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = get_len(src);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (size == 0)
		return (NULL);
	while (i < size - 1 && src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

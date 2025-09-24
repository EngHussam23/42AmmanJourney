/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:33 by halragga          #+#    #+#             */
/*   Updated: 2025/09/24 17:57:05 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_len(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

char	*find_new_line(const char *s)
{
	while (*s)
	{
		if (*s != '\n')
			s++;
		if (*s == '\n')
			return ((char *)s);
	}
	return (NULL);
}

char	*join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

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
	return (result);
}

char	substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sub_len;
	char	*sub_s;

	sub_len = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen - start < len)
		sub_len = ft_strlen(s) - start;
	else
		sub_len = len;
	if (slen < start)
		return (ft_calloc(1, 1));
	sub_s = malloc((sub_len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, s + start, sub_len);
	sub_s[sub_len] = '\0';
	return (sub_s);
}

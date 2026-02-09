/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:01:33 by halragga          #+#    #+#             */
/*   Updated: 2025/11/25 20:45:48 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(const char *s)
{
	size_t	x;

	x = 0;
	if (!s)
		return (x);
	while (s[x])
		x++;
	return (x);
}

char	*join(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
		s1 = str_duplicate("");
	if (!s1 && !s2)
		return (NULL);
	result = malloc(get_len(s1) + get_len(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*str_duplicate(const char *src)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!src)
		return (NULL);
	len = get_len(src);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*find_new_line(const char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s != '\n')
			s++;
		else
			return ((char *)s);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub_s;

	sub_len = 0;
	if (!s)
		return (NULL);
	s_len = get_len(s);
	if (s_len - start < len)
		sub_len = get_len(s) - start;
	else
		sub_len = len;
	if (s_len <= start)
		return (malloc(1));
	sub_s = malloc((sub_len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	cpy(sub_s, s + start, sub_len);
	sub_s[sub_len] = '\0';
	return (sub_s);
}

// return (malloc(1));

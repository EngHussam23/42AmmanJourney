/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:04:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/18 13:20:35 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	s3[ft_strlen(s3)] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (!ft_isascii(*s))
			return (NULL);
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

size_t	ft_strlen(const char *s)
{
	size_t		x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

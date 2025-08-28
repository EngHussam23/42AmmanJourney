/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:29:01 by halragga          #+#    #+#             */
/*   Updated: 2025/08/25 17:53:28 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_the_words(const char *s, char c)
{
	int	words_count;

	words_count = 0;
	while (*s)
	{
		if (*s != c)
		{
			words_count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words_count);
}

static int	get_word_length(const char *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static void	free_all(char **s, int words_count)
{
	int	i;

	i = 0;
	while (i < words_count)
	{
		if (s[i])
			free((char *)s[i]);
		i++;
	}
	free(s);
}

static int	fill_the_table(const char *s, char c, char **result)
{
	int	i;
	int	wl;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			wl = get_word_length(s, c);
			result[i] = (char *)malloc(sizeof(char) * (wl + 1));
			if (!result[i])
				return (i);
			ft_strlcpy(result[i], s, wl + 1);
			result[i][wl] = '\0';
			s += wl;
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words_count;
	int		fill_result;

	if (!s || c == '\0')
		return (NULL);
	words_count = count_the_words(s, c);
	fill_result = 0;
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	fill_result = fill_the_table(s, c, result);
	if (fill_result != -1)
	{
		free_all(result, fill_result);
		return (NULL);
	}
	result[words_count] = NULL;
	return (result);
}

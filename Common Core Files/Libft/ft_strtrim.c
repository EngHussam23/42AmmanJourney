/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:49:58 by halragga          #+#    #+#             */
/*   Updated: 2025/08/21 14:48:25 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (-1);
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		start_index;
	int		end_index;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start_index = start(s1, set);
	end_index = end(s1, set);
	len = end_index - start_index + 1;
	if (start_index > end(s1, set))
		return (ft_calloc(1, sizeof(char)));
	trimmed_str = malloc((len + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < len)
		trimmed_str[i++] = s1[start_index++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

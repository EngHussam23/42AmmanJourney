/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:49:58 by halragga          #+#    #+#             */
/*   Updated: 2025/08/16 18:25:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *trimmed_str;
	int i;
	int j;

	i = 0;
	j = ft_strlen(s1);
	trimmed_str = malloc((ft_strlen(s1) - ft_strlen(set)) * sizeof(char) + 1);
	if (!trimmed_str)
		return (NULL);
	if (s1)
	{
		while (s1[i] == set[i])
			i++;
	}
}

/*
ft_strtrim
char *ft_strtrim(char const *s1, char const *set);
-
s1: The string to be trimmed.
set: The string containing the set of characters
to be removed.
The trimmed string.
NULL if the allocation fails.
malloc
Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
*/
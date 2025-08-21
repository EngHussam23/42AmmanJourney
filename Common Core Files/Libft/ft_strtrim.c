/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:49:58 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 20:00:41 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(const char *s1, const char *set)
{
	int	set_index;
	int	s1_index;

	set_index = 0;
	s1_index = 0;
	while (set_index < (int)ft_strlen(set))
	{
		if (s1[s1_index] == set[set_index])
		{
			s1_index++;
			set_index = 0;
		}
		else
			set_index++;
	}
	return (s1_index);
}

static int	end(const char *s1, const char *set)
{
	int	set_index;
	int	s1_index;

	set_index = 0;
	if (ft_strlen(s1) == 0)
		return (0);
	s1_index = ft_strlen(s1) - 1;
	while (set_index < (int)ft_strlen(set))
	{
		if (s1[s1_index] == set[set_index])
		{
			s1_index--;
			set_index = 0;
		}
		else
			set_index++;
	}
	return (s1_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		start_index;
	int		end_index;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start_index = start(s1, set);
	end_index = end(s1, set);
	i = 0;
	if (start_index > end_index)
		return ("");
	else if (start_index == end_index)
	{
		trimmed_str = (char *)malloc(1 * sizeof(char));
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = malloc(((end(s1, set) - start(s1, set)) + 2) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	while (start_index <= end_index)
		trimmed_str[i++] = s1[start_index++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

/*int main(void)
{
	// Example usage of ft_strtrim
	char const *s1 = "  \t \t \n   \n\n\n\t";
	char const *s2 = "";
	char const *set = " \n\t";
	char *trimmed = ft_strtrim(s1, set);
	printf("Original: %s\n", s2);
	printf("Trimmed: %s\n", trimmed);
	// Free the allocated memory
	free(trimmed);
	return (0);
}*/

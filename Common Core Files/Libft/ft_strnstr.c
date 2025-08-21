/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:46 by halragga          #+#    #+#             */
/*   Updated: 2025/08/17 11:44:07 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t length)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ft_strlen(small) == 0)
		return ((char *) big);
	while (i < length && big[i])
	{
		j = 0;
		while (small[j] && i + j < length)
		{
			if (big[i + j] == small[j])
				j++;
			else
				break ;
			if (j == ft_strlen(small))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*int	main(int argc, char **argv)
{
	if (argc > 3)
		printf("Too many ARGUMNENTS!!!\n");
	else if (argc < 3)
		printf("Missing ARGUMNENTS!!!\n");
	else
	{
		printf("Standard result: ops! NO STANDARD FUNCTION TO TEST!!!\n");
		printf("My r e s u l t : %s\n", ft_strnstr(argv[1], argv[2], 5));
	}
}*/
/*
char	*ft_strnstr(const char *big, const char *small, size_t length)
{
	size_t		i;
	size_t		j;
	int			count;
	int			small_len;

	i = 0;
	j = 0;
	count = 0;
	small_len = ft_strlen(small);
	if (small_len == 0)
		return (big);
	while (i < length)
	{
		if (big[i] == small[j])
		{
			j++;
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == small_len)
			return (big + (i - count));
		i++;
	}
	return (NULL);
}
*/
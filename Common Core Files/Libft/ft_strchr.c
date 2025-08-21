/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:19 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 19:13:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s && s[i] != '\0')
	{
		if (!ft_isascii(s[i]))
			return (NULL);
		if (s[i] == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *) s);
	return (NULL);
}

/*int	main(void)
{
	printf("Standard result: %s\n", strchr("Hello Hussam", 'K'));
	printf("Reproduced result: %s\n", ft_strchr("Hello Hussam", 'K'));
	return (0);
}*/

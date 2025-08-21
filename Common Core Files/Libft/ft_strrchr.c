/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:52 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 19:16:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (*s)
	{
		if (s[i] == (unsigned char)c)
			ptr = (char *) s;
		s++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *) s);
	return (ptr);
}

/*int	main(void)
{
	printf("Standard result: %s\n", strrchr("Hello Hussam Alraggad", 'k'));
	printf("Reproduced result: %s\n", ft_strrchr("Hello Hussam Alraggad", 'k'));
	return (0);
}*/

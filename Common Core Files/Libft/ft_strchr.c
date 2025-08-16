/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:40:19 by halragga          #+#    #+#             */
/*   Updated: 2025/08/09 17:31:41 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



char	*ft_strchr(const char *s, int c)
{
	int	i;
	
	i = 0;
	while (*s)
	{
		if (s[i] == c)
			return ((char *) s);
		s++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *) s);
	return ("(null)");
}

/*int	main(void)
{
	printf("Standard result: %s\n", strchr("Hello Hussam", 'K'));
	printf("Reproduced result: %s\n", ft_strchr("Hello Hussam", 'K'));
	return (0);
}*/

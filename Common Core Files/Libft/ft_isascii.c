/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:25 by halragga          #+#    #+#             */
/*   Updated: 2025/08/13 18:53:32 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many arguments...\n");
	else if (argc < 2)
		printf("Missing argument...\n");
	else
	{
		printf("My Result: %d\n", ft_isascii(argv[1][0]));
		printf("Standard Result: %d\n", isascii(argv[1][0]));
	}
	return (0);
}*/

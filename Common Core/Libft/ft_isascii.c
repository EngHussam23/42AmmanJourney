/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:53:25 by halragga          #+#    #+#             */
/*   Updated: 2025/08/04 20:42:28 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 177)
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
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
}

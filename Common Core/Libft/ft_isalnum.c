/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:31:55 by halragga          #+#    #+#             */
/*   Updated: 2025/08/04 18:52:46 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 8;
	else if (c >= 48 && c <= 57)
		return (8);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	if (argc > 3)
		printf("Too many arguments...");
	else if (argc == 2)
	{
		printf("Hint: 0 means false.\n");
		printf("My result: %d\n", ft_isalnum(argv[1][0]));
		printf("Standard result: %d\n", isalnum(argv[1][0]));
	}
	else if (argc < 2)
		printf("Missing argments...");
	else
	{
		printf("Hint: 0 means false.\n");
		printf("My results: %d, %d\n", ft_isalnum(argv[1][0]), ft_isalnum(argv[2][0]));
		printf("Standard results: %d, %d\n", isalnum(argv[1][0]), isalnum(argv[2][0]));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:31:55 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 19:56:48 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (8);
	else if (c >= 48 && c <= 57)
		return (8);
	else
		return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many arguments...");
	else if (argc < 2)
		printf("Missing argments...");
	else
	{
		printf("Hint: 0 means false.\n");
		printf("My results: %d, %d\n", ft_isalnum(argv[1][0]));
		printf("Standard results: %d, %d\n", isalnum(argv[1][0]));
	}
	return (0);
}
*/

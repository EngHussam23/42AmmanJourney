/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:11:44 by halragga          #+#    #+#             */
/*   Updated: 2025/08/13 18:56:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many arguments...")
	else if (argc < 2)
		printf("Missing argument...");
	else
	{
		printf("------------------------------------------\n");
		printf("|                                        |\n");
		printf("|            Hint: 0 mean false          |\n");
		printf("|                                        |\n");
		printf("------------------------------------------\n");
		printf("Standard result: %d\n", isprint('\0'));
		printf("My Result: %d\n", ft_isprint('\0'));
	}
	return (0);
}
*/

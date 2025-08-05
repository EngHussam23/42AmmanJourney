/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:22:25 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 19:55:21 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many ARGUMENTS...");
	else if (argc < 2)
		printf("Missing ARGUMENT...");
	else
	{
		printf("Standard Result: %lu\n", strlen(argv[1]));
		printf("My Result: %lu\n", ft_strlen(argv[1]));
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:39:29 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 17:25:22 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <bsd/string.h>

#include "libft.h"

int	main(int argc, char *argv[])
{
	if (argc > 3)
		printf("Too many ARGUMENTS...\n");
	else if (argc < 3)
		printf("Missing ARGUMENTS...\n");
	else
	{
		printf("Standard Result: %zu\n", strlcpy(argv[2], argv[1], 5));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:16:08 by halragga          #+#    #+#             */
/*   Updated: 2025/08/31 19:40:23 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *email = "engraggad@gmail.com";
	char **parts = ft_split(email, '@');
	printf("%s\n", parts[0]);
	printf("%s\n", parts[1]);
	// Free the memory allocated by ft_split
	for (int i = 0; parts[i] != NULL; i++)
		free(parts[i]);
	free(parts);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:25:32 by halragga          #+#    #+#             */
/*   Updated: 2025/01/11 10:25:47 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**ft_table_malloc(void)
{
	int	**table;
	int	i;

	i = 0;
	table = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		table[i] = malloc(sizeof(int) * 4);
		i++;
	}
	write(1, "Memory allocated!\n", 18);
	return (table);
}

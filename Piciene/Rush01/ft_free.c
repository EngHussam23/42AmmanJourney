/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:44:43 by halragga          #+#    #+#             */
/*   Updated: 2025/01/11 15:44:59 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_free(int **table, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	write(1, "Memory is free!\n", 16);
}

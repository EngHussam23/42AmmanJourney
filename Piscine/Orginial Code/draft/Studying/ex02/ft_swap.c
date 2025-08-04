/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:05:08 by halragga          #+#    #+#             */
/*   Updated: 2025/01/05 18:05:11 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;	
	
}

int	main(void)
{
	int	x;
	int	y;
	
	x = 5;
	y = 3;
	printf("Before =>\nx = %d\ny = %d\n", x, y);
	ft_swap(&x, &y);
	printf("After =>\nx = %d\ny = %d\n", x, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:26:06 by halragga          #+#    #+#             */
/*   Updated: 2025/01/05 18:26:08 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	ptr1;
	int	ptr2;
	
	div = 
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	w;
	int	x;
	int*	y;
	int*	z;
	
	w = 12;
	x = 24;
//	y = &w;
//	z = &x;
	printf("Before => w = %d, x = %d", w, x);
	ft_div_mod(w, x, y, z);
	printf("After => w = %d, x = %d", w, x);
}

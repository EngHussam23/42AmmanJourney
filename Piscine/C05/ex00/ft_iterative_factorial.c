/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:00:16 by hussam            #+#    #+#             */
/*   Updated: 2025/01/29 00:00:19 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_factorial(int nb);

int ft_iterative_factorial(int nb)
{
	int i;

	i = nb - 1;
	if (nb < 0)
		return (-1);
	else if (nb == 0 || nb == 0)
		return (1);
	while (i > 0)
	{
		nb *= i;
		i--;
	}
	return (nb);
}

int main(void)
{
	printf("%d", ft_iterative_factorial(5));
	return (0);
}
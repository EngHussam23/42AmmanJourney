/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:44:54 by hussam            #+#    #+#             */
/*   Updated: 2025/01/29 08:44:56 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
Create a recursive function that returns the factorial of the number given as a parameter.

•If the argument is not valid the function should return 0.
•Overflows must not be handled, the function return will be undefined.
•Here’s how it should be prototyped :
int ft_recursive_factorial(int nb);
*/

int ft_recursive_factorial(int nb);

int ft_recursive_factorial(int nb)
{
	int i;

	i = nb - 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		//nb *= i--;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:16:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/11 14:08:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	int		x;

	ptr = "123546";
	printf("%x%x%x\n", 255, 255, 255);
	// ft_printf("%x%x%x\n\n\n", 255, 255, 255);

	printf("Char: [%c]\n", 'A');

	printf("String: [%s]\n", "Hello, 42!");

	x = 42;
	printf("Pointer: [%p]\n", &x);

	printf("Decimal: [%d]\n", -12345);

	printf("Integer: [%i]\n", 67890);

	printf("Unsigned: [%u]\n", 4294967295u);

	printf("Hex lower: [%x]\n", 305441741);

	printf("Hex upper: [%X]\n", 305441741);

	printf("Percent: [%%]\n");


	printf("Empty string: [%s]\n", "");
	printf("Null pointer: [%p]\n", NULL);
	printf("Zero: [%d] [%i] [%u] [%x] [%X]\n", 0, 0, 0u, 0, 0);

	return (0);
}
// %c: single character
// %s: string
// %p: pointer (hexadecimal)
// %d: decimal (base 10)
// %i: integer (base 10)
// %u: unsigned decimal
// %x: hexadecimal lowercase
// %X: hexadecimal uppercase
// %%: percent sign
// Edge cases
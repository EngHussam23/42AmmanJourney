/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:59:45 by halragga          #+#    #+#             */
/*   Updated: 2025/09/14 14:26:48 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int x = 42;
	int *px = &x;
	char *str = "hello";

	ft_printf("%p\n", px);   // prints the actual address of x
	ft_printf("%p\n", str);  // prints the address of the string
	ft_printf("%p\n", (void *)(uintptr_t)-ULONG_MAX);  // huge hex value
	return (0);
}

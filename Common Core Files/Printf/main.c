/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:59:45 by halragga          #+#    #+#             */
/*   Updated: 2025/09/14 17:54:36 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	test_moulitest_06;
	ft_printf("s: %s, p: %p, d:%d\n", "a string", &test_moulitest_06, 42);
	return (0);
}

/*
ASSERT_PRINTF("s: %s, p: %p, d:%d", "a string", &test_moulitest_06, 42);
ASSERT_PRINTF("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
*/
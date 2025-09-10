/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:16:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/10 16:24:01 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header_files/libft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*ptr;

	ptr = "123546";
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);
	return (0);
}

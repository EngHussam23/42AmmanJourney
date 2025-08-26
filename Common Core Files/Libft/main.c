/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:35:11 by halragga          #+#    #+#             */
/*   Updated: 2025/08/25 15:15:25 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("substr return:%s\n", substr(NULL, 1, 3));
	printf("ft_substr return:%s\n", ft_substr(NULL, 1, 3));
	return (0);
}
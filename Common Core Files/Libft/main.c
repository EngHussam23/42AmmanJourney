/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:16:08 by halragga          #+#    #+#             */
/*   Updated: 2025/08/31 19:40:23 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *email = "engraggad@gmail.com";
	printf("%s\n", ft_split(email, '@')[0]);
	printf("%s\n", ft_split(email, '@')[1]);
	return (0);
}

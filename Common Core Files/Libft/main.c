/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:35:11 by halragga          #+#    #+#             */
/*   Updated: 2025/08/31 11:12:59 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	str = "i just want this part #############";
	printf("ft_substr return:%s\n", ft_substr(str, 0, 22));
	free(str);
	return (0);
}

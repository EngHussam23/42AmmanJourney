/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:16:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/01 20:46:09 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>



char	t_strlen(unsigned int u, char str)	
{
	return (str - 32);
}

int	main(void)
{
	char	*str;

	str = "helloworld";
	printf ("%s", ft_strmapi(str, t_strlen)) ;
	return (0);
}

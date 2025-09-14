/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:53:22 by halragga          #+#    #+#             */
/*   Updated: 2025/08/24 17:28:54 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates over each character of the string 's', applying the function 'f' to
// each character.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (i < (int)ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}

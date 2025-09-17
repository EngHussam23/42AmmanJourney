/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/17 17:01:40 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*remains;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
}

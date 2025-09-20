/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/20 20:53:25 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	int			nbytes;
	char		*line;
	char		*buff;
	static char* stash;

	buff = malloc(BUFFER_SIZE + 1);
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	if (ft_strchr(buff, '\n'))
	{
		ft_strlcat(stash, buff, BUFFER_SIZE);
		line = buff;
		free(buff);
		return (line);
	}
	ft_strlcat(stash, buff, BUFFER_SIZE);
	//continue the other cases
	return(line);
}

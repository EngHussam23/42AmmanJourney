/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/20 21:01:47 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	int			nbytes;
	char		*line;
	char		*buff;
	static char	*stash;

	buff = malloc(BUFFER_SIZE + 1);
	nbytes = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	if (ft_strchr(buff, '\n'))
	{
		//push the buff by...
		ft_strlcat(stash, ft_strchr(buff, '\n'), BUFFER_SIZE);
		//push the buff by...
		line = buff;//not correct
		free(buff);
		return (line);
	}
	ft_strlcat(stash, buff, BUFFER_SIZE);
	//continue the other cases
	return(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/22 12:04:55 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stash_line(char *stash, char *buff, char *line, int nbytes)
{
	if (nbytes == BUFFER_SIZE)
	{}
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buff;
	char		*line;
	static char	*stash;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	buff[nbytes] = '\0';
	if (nbytes == 0)
		return (NULL);
	else
	{
		if (nbytes < BUFFER_SIZE)
		{
			line = malloc(nbytes + 1);
			line = buff;
			line[nbytes] = '\0';
			free(buff);
			return (line);
		}
		stash_line(stash, buff, line, nbytes);
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/21 20:01:11 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_l(char *ptr)
{
	int	index;

	index = 0;
	while (*ptr)
	{
		if (*ptr == '\n')
			return (index);
		ptr++;
		index++;
	}
	return (index);
}

char* get_next_line(int fd)
{
	int			nbytes;
	int			i;
	char 		*line;
	char		*buff;
	static char* stash;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	buff[nbytes] = '\0';
	i = 0;
	line = malloc(1);
	while (i < nbytes)
	{
		if (find_new_l(buff) || i <= find_new_l(buff))
			line[i] = buff[i];
		else
			stash[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	free(buff);
	return(line);
}

/*
line = malloc(BUFFER_SIZE + 1);
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes <= 0)
	{
		free(buff);
		free(line);
		return (NULL);
	}
*/

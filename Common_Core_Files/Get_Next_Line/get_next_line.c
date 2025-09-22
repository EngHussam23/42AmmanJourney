/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/22 14:32:33 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*store_line(char *stash, char *buff, char *line, int nbytes)
{
	int	i;

	i = 0;
	if (nbytes <= BUFFER_SIZE)
	{
		my_malloc(&line, nbytes + 1);
		if (!line)
			free(buff);
		while (i < nbytes)
		{
			if (buff[i] == '\n')
			{
				line[i] = buff[i++];
				break ;
			}
			line[i] = buff[i++];
		}
		line[i] = '\0';
		while (i < nbytes)
		{
			stash[i] = buff[i++];
		}
		free(buff);
		return (line);
	}
}

static void	my_malloc(char *mem, int mem_size)
{
	mem = malloc(mem_size);
	if (!mem)
		return (NULL);
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buff;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	buff[nbytes] = '\0';
	if (nbytes == 0)
		return (NULL);
	else
		store_line(&stash, buff, line, nbytes);
	return (line);
}

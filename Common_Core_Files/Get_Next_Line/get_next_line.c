/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/24 18:14:18 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stash_read(char *stash, char *buff, int nbytes)
{
	int		i;
	char	*line;

	i = -1;
	stash = malloc(nbytes + 1);
	if (!stash)
		return (NULL);
	while (++i < nbytes && buff[i] != '\n')
		stash[i] = buff[i];
	stash[i] = '\n';
	concatinate(line, stash, i);
	line[i + 1] = '\0';
	while (++i < nbytes)
	{
		stash[i] = buff[i];
	}
	return (line);
}

static char	*extract_line(char **stash)
{
	
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buff;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!find_new_line(stash))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes <= 0)
			return (NULL);
		buff[nbytes] = '\0';
		stash = join(stash, buff);
		if (stash)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return ();
}

/*
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes <= 0)
	{
		free(buff);
		free(stash);
		return (NULL);
	}
	else
	{
		buff[nbytes] = '\0';
		line = stash_read(stash, buff, nbytes);
		free(buff);
	}
	return (line);
*/
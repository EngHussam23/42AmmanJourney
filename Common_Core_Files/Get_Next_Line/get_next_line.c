/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/27 14:36:20 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*cpy(void *dest, const void *src, size_t cpysize)
{
	size_t		i;
	char		*cdest;
	const char	*csrc;

	if (cpysize == 0)
		return (dest);
	i = 0;
	csrc = (const char *)src;
	cdest = (char *)dest;
	while (i < cpysize)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*leftovers;
	int		i;
	int		j;

	i = 0;
	while (*stash[i] && *stash[i] != '\n')
		i++;
	if (*stash[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = *stash[j];
		j++;
	}
	line[j] = '\0';
	leftovers = NULL;
	if (*stash[i] == '\n' && *stash[i + 1])
		leftovers = str_duplicate(&*stash[i + 1], get_len(*stash) - (j + 1));
	free(*stash);
	*stash = leftovers;
	return (line);
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buff;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes <= 0)
	{
		free(buff);
		return (NULL);
	}
	while (nbytes > 0 && buff)
	{
		buff[nbytes] = '\0';
		stash = join(stash, buff);
		if (!stash)
		{
			free(buff);
			return (NULL);
		}
		nbytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (extract_line(&stash));
}

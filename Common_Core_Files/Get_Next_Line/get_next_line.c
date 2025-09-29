/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/29 20:33:03 by halragga         ###   ########.fr       */
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

	if (!*stash || !**stash)
		return (NULL);
	if (find_new_line(*stash))
	{
		line = ft_substr(*stash, 0, find_new_line(*stash) - *stash + 1);
		if ((find_new_line((*stash)) + 1))
		{
			leftovers = str_duplicate(find_new_line((*stash)) + 1);
			free((*stash));
			*stash = leftovers;
		}
		else
		{
			free(*stash);
			*stash = NULL;
		}
		return (line);
	}
	line = str_duplicate(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*buff;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!stash)
		stash = str_duplicate("");
	while (!find_new_line(stash))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes <= 0)
			break ;
		buff[nbytes] = '\0';
		stash = join(stash, buff);
		if (!stash)
			return (NULL);
	}
	free(buff);
	return (extract_line(&stash));
}

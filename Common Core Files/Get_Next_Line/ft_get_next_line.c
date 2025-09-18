/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/18 13:49:15 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

static char	*trim_stash(char *stash, int trim_length)
{
	char	*trimmed;

	if (!stash[trim_length])
	{
		free(stash);
		return (NULL);
	}
	trimmed = ft_substr(stash, trim_length, ft_strlen(stash) - trim_length);
	free(stash);
	return (trimmed);
}

static int	get_line_length(char *stash)
{
	int	count;

	count = 0;
	while (*stash != '\n' && *stash)
	{
		stash++;
		count++;
	}
	if (*stash == '\n')
		count++;
	return (count);
}

char	*ft_get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*stash;
	int			nbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[nbytes] = '\0';
	stash = ft_strjoin(stash, buff);
	free(buff);
	if (ft_strchr(stash, '\n'))
	{
		line = ft_substr(stash, 0, get_line_length(stash));
		stash = trim_stash(stash, get_line_length(stash));
	}
	else if (nbytes == 0 && stash && *stash)
	{
		line = ft_substr(stash, 0, ft_strlen(stash));
		stash = NULL;
	}
	return (line);
}

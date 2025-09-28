/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:16:42 by halragga          #+#    #+#             */
/*   Updated: 2025/09/28 20:32:26 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	stash_data(int fd, int nbytes, char *buff, char **stash)
{
	while (buff && !find_new_line(buff))
	{
		buff[nbytes] = '\0';
		(*stash) = join((*stash), buff);
		if (!(*stash))
		{
			free(buff);
			return ;
		}
		nbytes = read(fd, buff, BUFFER_SIZE);
	}
	//stopped here
}

static char	*read_to_buff(int fd, int nbytes, char *buff, char **stash)
{
	nbytes = read(fd, buff, BUFFER_SIZE);
	if (nbytes <= 0)
	{
		free(buff);
		if (nbytes == 0)
			return ((*stash));
		else
			return (NULL);
	}
	else
		stash_data(fd, nbytes, buff, &(*stash));
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
		return (NULL);
	stash = read_to_buff(fd, nbytes, buff, &stash);
	free(buff);
	return (extract_line(&stash));
}

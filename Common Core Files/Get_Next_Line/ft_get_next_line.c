/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/17 20:25:51 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

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
	stash = ft_strlcat(stash, buff, nbytes);
	if (ft_strchr(stash, '\n'))
		line = ......
	return (line);
}

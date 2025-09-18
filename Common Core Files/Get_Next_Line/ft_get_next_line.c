/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:54:08 by halragga          #+#    #+#             */
/*   Updated: 2025/09/18 18:08:19 by halragga         ###   ########.fr       */
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
}

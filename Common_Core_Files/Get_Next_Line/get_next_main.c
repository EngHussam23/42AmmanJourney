/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:21:55 by halragga          #+#    #+#             */
/*   Updated: 2025/09/28 20:15:01 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("testing.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}

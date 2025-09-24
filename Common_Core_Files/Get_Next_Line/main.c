/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:21:55 by halragga          #+#    #+#             */
/*   Updated: 2025/09/23 13:39:54 by halragga         ###   ########.fr       */
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
	line = get_next_line(fd);
	while (line)
	{
		printf("Line: %s", line);
	}
	free(line);
	return (0);
}

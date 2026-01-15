/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:57:09 by halragga          #+#    #+#             */
/*   Updated: 2025/12/06 18:30:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_height(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	// protect msg
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		game->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	parse_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		line_c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error while parsing map! Invalid file descriptor!\n");
		exit(1);
	}
	game->map.grid = NULL;
	game->map.height = 0;
	line = get_next_line(fd);
	line_c = 1;
	while (line)
	{
		game->map.grid[game->map.height] = malloc(sizeof(char *) * line_c++);
		game->map.grid[game->map.height++] = line;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	has_valid_chars(t_game *game)
{
}

int	is_recatngular(t_game *game)
{
}

void	validate_map(t_game *game)
{
}

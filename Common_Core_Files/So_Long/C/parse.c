/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:57:09 by halragga          #+#    #+#             */
/*   Updated: 2025/12/04 20:08:44 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error while parsing map! Invalid file descriptor!\n");
		exit(1);
	}
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

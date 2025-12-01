/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:52:21 by halragga          #+#    #+#             */
/*   Updated: 2025/12/01 19:50:17 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*Standard Includes, not ready still need updates*/
# include <mlx.h> /*rendering visuals mlx_init(), mlx_new_window*/
# include <fcntl.h> /*opening files (maps)*/
# include <unistd.h> /*read from, write to, and close files*/
# include <stdlib.h> /*memory management: malloc(), free(). And exit()*/
# include <math.h> /*math unctions if needed*/

/*My defined includes*/
# include "Libft/libft.h" /*My own library*/

/*Macros (constants)*/
/*
Key codes:
'W' : 119, -> W_KEY 119
'A' : 97,  -> A_KEY 97
'S' : 115, -> S_KEY 115
'D' : 100, -> D_KEY 100
ESC : 65307,  -> ESC   65307 (this value is on Linux X11.
								27 for macOS for example)
*/
# define TILE 32
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

/*Data Structs*/
typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectables;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		wall;
	t_img		floor;
	t_img		player_img;
	t_img		collectable;
	t_img		exit;
}	t_game;

/*Functions*/
/*Parsing & Valiation*/
void	parse_map(t_game *game, char *file);
void	validate_map(t_game *game);
int		is_recatngular(t_game *game);
int		has_valid_chars(t_game *game);

/*Rendering*/
void	render(t_game *game);
void	render_tile(t_game *game, int x, int y);

/*Movement*/
int		handle_key(int key, t_game *game);
void	move_player(t_game *game, int dx, int dy);

/*Cleanup*/
void	free_map(t_game *game);
void	destroy_images(t_game *game);
void	exit_game(t_game *game);

#endif

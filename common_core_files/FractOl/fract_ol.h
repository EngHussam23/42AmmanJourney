/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:18:02 by halragga          #+#    #+#             */
/*   Updated: 2026/01/21 16:49:38 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

/* Standard Includes */
# include "mlx.h"
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>

/* My defined includes */
# include "Libft/libft.h"

/* Window Size */
# define WIDTH 500
# define HEIGHT 500

/* Key codes in Linux */
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define C_KEY 99
# define R_KEY 114
# define PLUS_KEY 61
# define MINUS_KEY 45

/* Mouse Codes */
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

/* Fractal Types */
# define MANDELBROT 1
# define JULIA 2

/* Data Structs */

/* Real & Imaginary axises values */
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

/* Image varibles */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* Fractol variables */
typedef struct s_fract
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_itr;
	int			clr_shift;
	int			julia_mode;
	char		*name;
	t_complex	julia_c;
}	t_fract;

/* MLX */
typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_fract		fract;
	t_complex	cmp;
	t_img		img;
}	t_mlx_data;

/* Functions' Signatures */
/* Render */
void	show_guide(void);
int		open_window(t_mlx_data *data);
int		render_image(t_mlx_data *data);

/* Events handling */
int		key_handler(int keycode, void *vars);
int		mouse_move(int x, int y, t_mlx_data *data);
int		mouse_handler(int button, int x, int y, t_mlx_data *data);

/* Fractals */
void	put_pixel(t_mlx_data *data, int x, int y, int color);
void	julia(t_mlx_data *data);
void	mandelbrot(t_mlx_data *data);
void	phoenix(t_mlx_data *data);
int		init_fract(t_mlx_data *data, int argc, char **argv);

/* Colors */
int		colorize(int itr, int max_itr, int shift);

#endif

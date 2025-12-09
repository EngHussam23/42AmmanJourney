/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:18:02 by halragga          #+#    #+#             */
/*   Updated: 2025/12/09 19:55:28 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

/* Standard Includes */
# include <mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>

/* My defined includes */
# include "Libft/libft.h"

/* Window Size */
# define WIN_WIDTH 1500
# define WIN_HEIGHT 880

/* Key codes in Linux */
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define UP_KEY 65362
# define RIGHT_KEY 65363
# define DOWN_KEY 65364
# define PLUS_KEY 61
# define MINUS_KEY 45
# define C_KEY 99

/* Mouse Codes */
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

/* Fractal Types */
# define MANDELBROT 1
# define JULIA 2

/* Image Structure */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* Main Fractal Structure */
typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	julia_x;
	double	julia_y;
	int		max_iter;
	int		color;
}	t_fractal;

/* Init */
void	init_fractal(t_fractal *f);

/* Render */
void	render_fractal(t_fractal *f);
void	put_pixel(t_img *img, int x, int y, int color);

/* Fractals */
double	ft_atof(const char *str);
int		mandelbrot(double cr, double ci, int max_iter);
int		julia(double zr, double zi, t_fractal *f);

/* Colors */
int		get_color(int iter, int max_iter, int scheme);

/* Events */
int		handle_keypress(int key, t_fractal *f);
int		handle_close(t_fractal *f);

#endif

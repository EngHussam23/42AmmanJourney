/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 11:18:02 by halragga          #+#    #+#             */
/*   Updated: 2025/12/07 12:01:42 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

/* Standard Includes */
# include <mlx.h> /*rendering visuals mlx_init(), mlx_new_window*/
# include <unistd.h> /*read from, write to, and close files*/
# include <stdlib.h> /*memory management: malloc(), free(). And exit()*/
# include <math.h> /*math functions for the fractal calculations*/

/* My defined includes */
# include "Libft/libft.h" /*My own library*/

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
	void	*img; /* MLX image pointer */
	char	*addr; /* Pixel data address from mlx_get_data_addr */
	int		bpp; /* Bits per pixel (color depth) */
	int		line_len; /* Bytes per row in the image */
	int		endian; /* Byte order: 0 = little, 1 = big */
}	t_img;

/* Main Fractal Structure */
typedef struct s_fractal
{
	void	*mlx; /* MLX connection pointer */
	void	*win; /* Window pointer */
	t_img	img; /* Image buffer for rendering */
	int		type; /* MANDELBROT or JULIA */
	double	zoom; /* Zoom level (smaller = more zoomed) */
	double	offset_x; /* Horizontal pan offset */
	double	offset_y; /* Vertical pan offset */
	double	julia_x; /* Julia set constant (real part) */
	double	julia_y; /* Julia set constant (imaginary part) */
	int		max_iter; /* Iteration limit (detail level) */
	int		color; /* Current color scheme */
}	t_fractal;

#endif

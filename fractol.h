/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:23:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 04:06:54 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fractal.h

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>

# define SCROLL_UP 4
# define SCROLL_DOWN 5

struct	s_fractal;

typedef struct s_fractal
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	int		max_iter;
	int		color;
	int		(*calc_color)(double c_re, double c_im, struct s_fractal *fractal);
}	t_fractal;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_fractal	fractal;
	int			width;
	int			height;
}	t_data;

typedef struct s_pixel_data
{
	int		*colors_row_prev;
	int		*colors_row_curr;
	double	re_factor;
	double	im_factor;
	int		x;
	int		y;
}	t_pixel_data;

// fractal
int		calculate_color_psyche(double c_re, double c_im, t_fractal *fractal);
int		calculate_color_classic(double c_re, double c_im, t_fractal *fractal);
int		calculate_color_perso(double z_re, double z_im, t_fractal *fractal);
// draw
void	draw_fractal(t_data *data);
// command
void	init_command(t_data *data);
int		mouse_zoom(int button, int x, int y, t_data *data);
int		handle_exit(t_data *data);
// command bonus
void	color_shift(t_data *data);
void	arrow_move(t_data *data, int keycode);
// interpolate
void	interpolate_vertical(t_data *data, t_pixel_data *pix_data);
void	interpolate_horizontal(t_data *data, t_pixel_data *pixel_data);
// draw_utility
void	set_pixel(t_data *data, int x, int y, int color);
void	process_pixel(t_data *data, double c_im, t_pixel_data *pixel_data);

#endif

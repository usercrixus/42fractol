/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:30:22 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 02:33:01 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(t_data *data, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	*(int *)(data->img_data + pixel_index) = color;
}

void	process_pixel(t_data *data, double c_im, t_pixel_data *pixel_data)
{
	double	c_re;
	int		color;

	c_re = data->fractal.min_re + pixel_data->x * pixel_data->re_factor;
	color = data->fractal.calc_color(c_re, c_im, &data->fractal);
	pixel_data->colors_row_curr[pixel_data->x] = color;
	set_pixel(data, pixel_data->x, pixel_data->y, color);
	interpolate_horizontal(data, pixel_data);
	interpolate_vertical(data, pixel_data);
}

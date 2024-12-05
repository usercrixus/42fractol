/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:07:25 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 02:33:08 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	swap_rows(t_pixel_data *pixel_data)
{
	int	*temp;

	temp = pixel_data->colors_row_prev;
	pixel_data->colors_row_prev = pixel_data->colors_row_curr;
	pixel_data->colors_row_curr = temp;
}

void	process_row(t_data *data, t_pixel_data *pixel_data)
{
	double	c_im;
	int		x;

	c_im = data->fractal.max_im - pixel_data->y * pixel_data->im_factor;
	x = 0;
	while (x < data->width)
	{
		pixel_data->x = x;
		process_pixel(data, c_im, pixel_data);
		x += 2;
	}
}

void	init_pixel_data(t_pixel_data *pixel_data, t_data *data)
{
	pixel_data->colors_row_prev = malloc(data->width * sizeof(int));
	pixel_data->colors_row_curr = malloc(data->width * sizeof(int));
	if (!pixel_data->colors_row_prev || !pixel_data->colors_row_curr)
	{
		if (pixel_data->colors_row_prev)
			free(pixel_data->colors_row_prev);
		if (pixel_data->colors_row_curr)
			free(pixel_data->colors_row_curr);
		handle_exit(data);
	}
	pixel_data->re_factor = (data->fractal.max_re - data->fractal.min_re)
		/ (data->width - 1);
	pixel_data->im_factor = (data->fractal.max_im - data->fractal.min_im)
		/ (data->height - 1);
}

void	draw_fractal(t_data *data)
{
	t_pixel_data	pixel_data;
	int				y;

	init_pixel_data(&pixel_data, data);
	y = 0;
	while (y < data->height)
	{
		pixel_data.y = y;
		process_row(data, &pixel_data);
		swap_rows(&pixel_data);
		y += 2;
	}
	free(pixel_data.colors_row_prev);
	free(pixel_data.colors_row_curr);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

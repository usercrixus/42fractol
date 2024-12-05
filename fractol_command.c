/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:36:04 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 04:04:06 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button == SCROLL_UP)
		zoom_factor = 0.97;
	else if (button == SCROLL_DOWN)
		zoom_factor = 1.03;
	else
		return (0);
	mouse_re = data->fractal.min_re + (double)x / data->width
		* (data->fractal.max_re - data->fractal.min_re);
	mouse_im = data->fractal.max_im - (double)y / data->height
		* (data->fractal.max_im - data->fractal.min_im);
	data->fractal.min_re = mouse_re
		+ (data->fractal.min_re - mouse_re) * zoom_factor;
	data->fractal.max_re = mouse_re
		+ (data->fractal.max_re - mouse_re) * zoom_factor;
	data->fractal.min_im = mouse_im
		+ (data->fractal.min_im - mouse_im) * zoom_factor;
	data->fractal.max_im = mouse_im
		+ (data->fractal.max_im - mouse_im) * zoom_factor;
	draw_fractal(data);
	return (0);
}

int	close_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	handle_exit(t_data *data)
{
	close_window(data);
	mlx_loop_end(data->mlx);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_exit(data);
	if (keycode == 99)
	{
		color_shift(data);
		draw_fractal(data);
	}
	if (keycode >= 65361 && keycode <= 65364)
	{
		arrow_move(data, keycode);
		draw_fractal(data);
	}
	return (0);
}

void	init_command(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_zoom, data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 0, handle_exit, data);
}

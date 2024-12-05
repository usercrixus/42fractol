/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_command_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 04:03:56 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 04:09:39 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_data *data)
{
	if (data->fractal.color == 0xDFFFF)
		data->fractal.color = 0xFFFFF;
	else
		data->fractal.color = 0xDFFFF;
}

void	arrow_move(t_data *data, int keycode)
{
	double	range_re;
	double	range_im;

	range_im = data->fractal.max_im - data->fractal.min_im;
	range_re = data->fractal.max_re - data->fractal.min_re;
	if (keycode == 65361)
	{
		data->fractal.min_re -= range_re * 0.05;
		data->fractal.max_re -= range_re * 0.05;
	}
	else if (keycode == 65363)
	{
		data->fractal.min_re += range_re * 0.05;
		data->fractal.max_re += range_re * 0.05;
	}
	else if (keycode == 65362)
	{
		data->fractal.min_im += range_im * 0.05;
		data->fractal.max_im += range_im * 0.05;
	}
	else if (keycode == 65364)
	{
		data->fractal.min_im -= range_im * 0.05;
		data->fractal.max_im -= range_im * 0.05;
	}
}

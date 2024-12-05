/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_interpolate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:21:35 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 02:22:22 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	interpolate_vertical(t_data *data, t_pixel_data *pix_data)
{
	int	color_up ;
	int	inter_color;
	int	color_diag;
	int	color_left;
	int	inter_color_diag;

	if (pix_data->y > 0)
	{
		color_up = pix_data->colors_row_prev[pix_data->x];
		inter_color = (pix_data->colors_row_curr[pix_data->x] + color_up)
			/ 2;
		set_pixel(data, pix_data->x, pix_data->y - 1, inter_color);
		if (pix_data->x > 0)
		{
			color_diag = pix_data->colors_row_prev[pix_data->x - 2];
			color_left = pix_data->colors_row_curr[pix_data->x - 2];
			inter_color_diag = (pix_data->colors_row_curr[pix_data->x]
					+ color_left + color_up + color_diag) / 4;
			set_pixel(data, pix_data->x - 1, pix_data->y - 1, inter_color_diag);
		}
	}
}

void	interpolate_horizontal(t_data *data, t_pixel_data *pixel_data)
{
	int	color_left;
	int	interpolated_color;

	if (pixel_data->x > 0)
	{
		color_left = pixel_data->colors_row_curr[pixel_data->x - 2];
		interpolated_color = (pixel_data->colors_row_curr[pixel_data->x]
				+ color_left) / 2;
		set_pixel(data, pixel_data->x - 1, pixel_data->y, interpolated_color);
	}
}

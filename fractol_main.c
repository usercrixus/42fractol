/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:45 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 04:19:35 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_data(t_data *data)
{
	data->width = 800;
	data->height = 800;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Fractal");
	if (!data->win)
		return (0);
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		return (0);
	data->img_data = mlx_get_data_addr
		(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	if (!data->img_data)
		return (0);
	return (1);
}

void	init_fractal(t_data *data, int function)
{
	double	aspect_ratio;

	aspect_ratio = (double)data->height / data->width;
	data->fractal.min_re = -2.0;
	data->fractal.max_re = 2.0;
	data->fractal.min_im = -2.0 * aspect_ratio;
	data->fractal.max_im = 2.0 * aspect_ratio;
	data->fractal.max_iter = 300;
	data->fractal.color = 0xFFFFF;
	if (function == 1)
		data->fractal.calc_color = calculate_color_psyche;
	else if (function == 2)
		data->fractal.calc_color = calculate_color_classic;
	else if (function == 3)
		data->fractal.calc_color = calculate_color_perso;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		function;

	if (argc != 2)
		return (1);
	if (argv[1][0] == '1' && argv[1][1] == '\0')
		function = 1;
	else if (argv[1][0] == '2' && argv[1][1] == '\0')
		function = 2;
	else if (argv[1][0] == '3' && argv[1][1] == '\0')
		function = 3;
	else
		return (1);
	if (!init_data(&data))
		return (0);
	init_command(&data);
	init_fractal(&data, function);
	draw_fractal(&data);
	mlx_loop(data.mlx);
	if (data.mlx)
		mlx_destroy_display(data.mlx);
	return (0);
}

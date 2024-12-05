/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:15:48 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/05 04:26:17 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_color_psyche(double z_re, double z_im, t_fractal *fractal)
{
	double	z_re2;
	double	z_im2;
	int		iter;

	iter = 0;
	while (iter < fractal->max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		z_im = 2 * z_re * z_im - 0.3842;
		z_re = z_re2 - z_im2 - 0.70176;
		iter++;
	}
	if (iter == fractal->max_iter)
		return (0x000000);
	return (iter * fractal->color / fractal->max_iter);
}

int	calculate_color_perso(double z_re, double z_im, t_fractal *fractal)
{
	double	z_re2;
	double	z_im2;
	double	temp_re;
	double	temp_im;
	int		iter;

	iter = 0;
	while (iter < fractal->max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4.0)
			break ;
		temp_re = z_re2 - z_im2 - 0.8;
		temp_im = -2 * z_re * z_im + 0.156;
		z_re = temp_re;
		z_im = temp_im;
		iter++;
	}
	if (iter == fractal->max_iter)
		return (0x000000);
	return ((iter * fractal->color) / fractal->max_iter);
}

int	calculate_color_classic(double c_re, double c_im, t_fractal *fractal)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;

	z_re = c_re;
	z_im = c_im;
	iter = 0;
	while (iter < fractal->max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 2.0)
			break ;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + c_re;
		iter++;
	}
	if (iter == fractal->max_iter)
		return (0x000000);
	return (iter * fractal->color / fractal->max_iter);
}

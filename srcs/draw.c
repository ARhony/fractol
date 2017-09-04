/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:47:23 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:47:28 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *env)
{
	long double		x;
	long double		y;
	int				i;

	i = 0;
	y = -1;
	while (++y < env->h)
	{
		x = -1;
		while (++x < env->w)
		{
			i = (env->set == 1 ? mandelbrot(env, x, y)
					: julia_calcul(env, x, y));
			if (i < env->mi)
				put_pixel_to_img(env, x, y,
						env->colors[(i + env->cs) % env->nbc]);
		}
	}
	use_img(env);
}

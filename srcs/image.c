/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:47:48 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:47:50 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_img(t_env *env, int x, int y, int color)
{
	int		i;

	if (x > 0 && y > 0 && x < env->w && y < env->h)
	{
		i = (x * (env->bpp / 8)) + (y * env->size);
		env->pixel_img[i] = color;
		env->pixel_img[++i] = color >> 8;
		env->pixel_img[++i] = color >> 16;
	}
}

void	init_image(t_env *env)
{
	env->img = mlx_new_image(env->mlx, env->w, env->h);
	env->pixel_img = mlx_get_data_addr(env->img, &(env->bpp),
		&(env->size), &(env->ed));
}

void	use_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	init_image(env);
}

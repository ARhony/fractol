/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:47:57 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:47:59 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_colors(t_env *env, int nbc)
{
	int					i;
	long double			f;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;

	env->colors = (int*)malloc(sizeof(int) * nbc);
	f = 0;
	i = -1;
	while (++i < nbc)
	{
		r = (cos(f) + 1) * ((nbc * 2) - 1);
		g = (sin(f) + 1) * ((nbc * 2) - 1);
		b = (-cos(f) + 1) * ((nbc * 2) - 1);
		env->colors[i] = b << 16 | g << 8 | r;
		f += M_PI / nbc;
	}
	env->cs = 0;
	env->nbc = nbc;
}

void		set_hooks(t_env *env)
{
	mlx_hook(env->win, 2, 0, key_press_hook, env);
	mlx_hook(env->win, 4, 0, mouse_wheel_hook, env);
	mlx_hook(env->win, 6, 0, mouse_hook, env);
	mlx_hook(env->win, 12, 0, expose, env);
}

t_env		*init_env(int set)
{
	t_env				*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->w = 900;
	env->h = 900;
	env->win = mlx_new_window(env->mlx, env->w, env->h, "fractol");
	env->set = set;
	env->updated = 1;
	env->mx = 0.0;
	env->my = 0.0;
	env->mi = 64;
	env->z = 1.0;
	env->nbc = 64;
	env->xs = 0.0;
	env->ys = 0.0;
	env->cre = 0.0;
	env->cim = 0.0;
	init_image(env);
	init_colors(env, env->nbc);
	return (env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:47:40 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:47:41 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_wheel_hook(int button, int x, int y, t_env *env)
{
	if (button == 5)
	{
		x -= env->w / 2;
		y -= env->h / 2;
		env->z = (env->z) * 1.1;
		env->xs += x / env->z / 1.5;
		env->ys += y / env->z / 1.5;
	}
	else if (button == 4)
	{
		if (env->z > 0)
			env->z = (env->z) / 1.1;
	}
	return (0);
}

int		mouse_hook(int x, int y, t_env *env)
{
	env->mx = (long double)x;
	env->my = (long double)y;
	env->updated = 1;
	return (0);
}

int		key_press_hook(int keycode, t_env *env)
{
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == 126)
		env->ys += 20;
	if (keycode == 123)
		env->xs += 20;
	if (keycode == 125)
		env->ys -= 20;
	if (keycode == 124)
		env->xs -= 20;
	if (keycode == 34 && env->mi < 4096)
		env->mi += 2;
	if (keycode == 31 && env->mi > 2)
		env->mi -= 2;
	if (keycode == 8)
		env->cs++;
	env->updated = 1;
	return (0);
}

int		expose(t_env *env)
{
	if (env->updated)
	{
		draw(env);
		infos(env);
	}
	env->updated = 0;
	return (0);
}

int		loop_hook(t_env *env)
{
	if (env->updated)
		expose(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:47:08 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:47:14 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mandelbrot(t_env *env, long double re, long double im)
{
	long double		xn;
	long double		x;
	long double		y;
	int				i;

	x = 0;
	y = 0;
	i = 0;
	re = cal_point(env, re, env->xs);
	im = cal_point(env, im, env->ys);
	while (x * x + y * y <= 4 && i < env->mi)
	{
		xn = x * x - y * y + re;
		y = 2 * x * y + im;
		x = xn;
		i++;
	}
	return (i);
}

int				julia_cubbed(t_env *env, long double x, long double y)
{
	int				i;
	long double		tmp;

	i = 0;
	x = cal_point(env, x, env->xs);
	y = cal_point(env, y, env->ys);
	while (x * x + y * y <= 4 && i < env->mi)
	{
		tmp = x * x * x - y * y * x - (2 * x * y * y) + env->cre;
		y = 2 * x * x * y - y * y * y + env->cim;
		x = tmp;
		i++;
	}
	return (i);
}

int				julia(t_env *env, long double x, long double y)
{
	int				i;
	long double		tmp;

	i = 0;
	x = cal_point(env, x, env->xs);
	y = cal_point(env, y, env->ys);
	while (x * x + y * y < 4 && i < env->mi)
	{
		tmp = x * x - y * y + env->cre;
		y = 2 * x * y + env->cim;
		x = tmp;
		i++;
	}
	return (i);
}

int				julia_calcul(t_env *env, long double x, long double y)
{
	env->cre = env->mx * 4.0 / env->w - 2.0;
	env->cim = env->my * 4.0 / env->h - 2.0;
	return (env->set == 2 ? julia(env, x, y) : julia_cubbed(env, x, y));
}

long double		cal_point(t_env *env, long double new, long double tmp)
{
	new = ((4.0 * new / env->w - 2.0) / env->z)
		+ (tmp / env->w);
	return (new);
}

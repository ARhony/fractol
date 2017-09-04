/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:48:18 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:48:20 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		infos(t_env *env)
{
	mlx_string_put(env->mlx, env->win,
			20, 10, 0x00FF0000, "ITERATION");
	mlx_string_put(env->mlx, env->win,
			20, 30, 0x00FF0000, ft_itoa(env->mi));
}

void		usage(void)
{
	ft_putendl("Usage : ./fractol");
	ft_putendl("1 : Mandelbrot\n2 : Julia\n3 : Julia cubed");
	exit(0);
}

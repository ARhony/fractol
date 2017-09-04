/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:48:08 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:48:10 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env		*env;

	env = NULL;
	if (ac == 2 && (ft_strcmp(av[1], "1") == 0 ||
					ft_strcmp(av[1], "2") == 0 ||
					ft_strcmp(av[1], "3") == 0))
		env = init_env(ft_atoi(&av[1][0]));
	else
		usage();
	init_image(env);
	set_hooks(env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
}

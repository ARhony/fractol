/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 02:48:44 by aramon            #+#    #+#             */
/*   Updated: 2017/05/19 02:48:47 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w;
	int				h;
	char			*pixel_img;
	int				bpp;
	int				size;
	int				ed;
	int				set;
	int				updated;
	long double		mx;
	long double		my;
	int				mi;
	long double		z;
	long double		xs;
	long double		ys;
	long double		cre;
	long double		cim;
	int				*colors;
	int				cs;
	int				nbc;
}				t_env;

void			usage(void);
t_env			*init_env(int set);
int				loop_hook(t_env *env);
void			exit_fractol(t_env *env);
void			draw(t_env *env);
void			set_hooks(t_env *env);
int				key_press_hook(int keycode, t_env *env);
int				mouse_hook(int x, int y, t_env *env);
int				mouse_wheel_hook(int button, int x, int y, t_env *env);
void			put_pixel_to_img(t_env *env, int x, int y, int color);
void			init_image(t_env *env);
void			use_img(t_env *env);
int				mandelbrot(t_env *env, long double re, long double im);
int				julia_cubbed(t_env *env, long double x, long double y);
int				julia(t_env *env, long double x, long double y);
int				julia_calcul(t_env *env, long double x, long double y);
void			init_colors(t_env *env, int nbc);
long double		cal_point(t_env *env, long double new, long double tmp);
void			splash(t_env *env);
int				expose(t_env *env);
void			infos(t_env *env);

#endif

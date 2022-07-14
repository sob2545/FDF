/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:55:28 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 14:09:04 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

void	obj_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP && fdf->mlx->handler.mv_y > -5000)
		fdf->mlx->handler.mv_y -= 20;
	else if (keycode == KEY_DOWN && fdf->mlx->handler.mv_y < 5000)
		fdf->mlx->handler.mv_y += 20;
	else if (keycode == KEY_LEFT && fdf->mlx->handler.mv_x > -5000)
		fdf->mlx->handler.mv_x -= 20;
	else if (keycode == KEY_RIGHT && fdf->mlx->handler.mv_x < 5000)
		fdf->mlx->handler.mv_x += 20;
}

void	rotate_handler(double *angle, double pi, int flag)
{
	if (flag == 1)
	{
		//if (*angle >= 360 * pi)
		//	*angle -= (360 * pi);
		*angle += (15 * pi);
	}
	else
	{
		//if (*angle <= -(360 * pi))
		//	*angle += (360 * pi);
		*angle -= (15 * pi);
	}
}

void	obj_rotate(int keycode, t_fdf *fdf)
{
	double	pi;

	pi = M_PI / 180;
	if (keycode == KEY_Q)
		rotate_handler(&(fdf->mlx->handler.angle_z), pi, 1);
	else if (keycode == KEY_E)
		rotate_handler(&(fdf->mlx->handler.angle_z), pi, 2);
	else if (keycode == KEY_W)
		rotate_handler(&(fdf->mlx->handler.angle_y), pi, 1);
	else if (keycode == KEY_S)
		rotate_handler(&(fdf->mlx->handler.angle_y), pi, 2);
	else if (keycode == KEY_A)
		rotate_handler(&(fdf->mlx->handler.angle_x), pi, 1);
	else if (keycode == KEY_D)
		rotate_handler(&(fdf->mlx->handler.angle_x), pi, 2);
}

void	obj_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ZM_U && fdf->mlx->handler.scale < 1000)
		fdf->mlx->handler.scale *= 5;
	else if (keycode == KEY_ZM_D && fdf->mlx->handler.scale > 0.0001)
		fdf->mlx->handler.scale *= 0.1;
}

void	obj_init(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
	{
		fdf->mlx->handler.angle_x = 0;
		fdf->mlx->handler.angle_y = 0;
		fdf->mlx->handler.angle_z = 0;
		fdf->mlx->handler.scale = fdf->mlx->handler.first_scale;
		fdf->mlx->handler.mv_x = WIN_W / 2;
		fdf->mlx->handler.mv_y = WIN_H / 2;
		fdf->mlx->handler.pro_mod = 0;
		fdf->mlx->handler.line_mod = 0;
		fdf->mlx->handler.line_mod = 0;
	}
}

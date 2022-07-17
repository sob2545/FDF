/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:10:36 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:26:20 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

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
	}
}

void	angle_init(t_fdf *fdf)
{
	if (fdf->mlx->handler.angle_x >= 360)
		fdf->mlx->handler.angle_x -= 360;
	else if (fdf->mlx->handler.angle_x <= -360)
		fdf->mlx->handler.angle_x += 360;
	else if (fdf->mlx->handler.angle_x >= 360)
		fdf->mlx->handler.angle_y -= 360;
	else if (fdf->mlx->handler.angle_x <= -360)
		fdf->mlx->handler.angle_y += 360;
	else if (fdf->mlx->handler.angle_x >= 360)
		fdf->mlx->handler.angle_z -= 360;
	else if (fdf->mlx->handler.angle_x <= -360)
		fdf->mlx->handler.angle_z += 360;
}

void	obj_rotate(int keycode, t_fdf *fdf)
{
	double	angle;

	angle = 30 * M_PI / 180;
	if (keycode == KEY_S)
		fdf->mlx->handler.angle_x += angle;
	else if (keycode == KEY_W)
		fdf->mlx->handler.angle_x -= angle;
	else if (keycode == KEY_D)
		fdf->mlx->handler.angle_y += angle;
	else if (keycode == KEY_A)
		fdf->mlx->handler.angle_y -= angle;
	else if (keycode == KEY_E)
		fdf->mlx->handler.angle_z += angle;
	else if (keycode == KEY_Q)
		fdf->mlx->handler.angle_z -= angle;
}

void	obj_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP && fdf->mlx->handler.mv_y > -3000)
		fdf->mlx->handler.mv_y -= 30;
	else if (keycode == KEY_DOWN && fdf->mlx->handler.mv_y < 3000)
		fdf->mlx->handler.mv_y += 30;
	else if (keycode == KEY_LEFT && fdf->mlx->handler.mv_x > -3000)
		fdf->mlx->handler.mv_x -= 30;
	else if (keycode == KEY_RIGHT && fdf->mlx->handler.mv_x < 3000)
		fdf->mlx->handler.mv_x += 30;
	else if (keycode == KEY_ZM_U)
		(fdf->mlx->handler.scale) += fdf->mlx->handler.scale * 0.1;
	else if (keycode == KEY_ZM_D)
		(fdf->mlx->handler.scale) -= fdf->mlx->handler.scale * 0.1;
}

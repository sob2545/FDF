/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:10:36 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 16:17:06 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_rotate(int keycode, t_fdf *fdf)
{
	double	angle;

	angle = 0;
	if (angle > 360)
		angle -= 360;
	if (keycode == KEY_UP && fdf->mlx->handler.mv_y > -3000)
		fdf->mlx->handler.mv_y -= 30;
	else if (keycode == KEY_DOWN && fdf->mlx->handler.mv_y < 3000)
		fdf->mlx->handler.mv_y += 30;
	else if (keycode == KEY_LEFT && fdf->mlx->handler.mv_x > -3000)
		fdf->mlx->handler.mv_x -= 30;
	else if (keycode == KEY_RIGHT && fdf->mlx->handler.mv_x < 3000)
		fdf->mlx->handler.mv_x += 30;
	else if (keycode == KEY_W)
		fdf->mlx->handler.angle_x += angle;
	else if (keycode == KEY_S)
		fdf->mlx->handler.angle_x -= angle;
	else if (keycode == KEY_A)
		fdf->mlx->handler.angle_y += angle;
	else if (keycode == KEY_Q)
		fdf->mlx->handler.angle_y -= angle;
	else if (keycode == KEY_E)
		fdf->mlx->handler.angle_z += angle;
	else if (keycode == KEY_D)
		fdf->mlx->handler.angle_z -= angle;
}


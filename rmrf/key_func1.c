/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:08:13 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 16:20:44 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	terminate(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->mlx->ucs.h)
	{
		free(fdf->point[i]);
		i++;
	}
	free(fdf->point);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img);
	mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	exit (0);
}

void	angle_init(t_handler *handler, int flag)
{
	if (flag == 0)
	{
		handler->angle_x = 0;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	else if (flag == 1)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	else if (flag == 2)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 90;
	}
}

void	set_projection(int key, t_fdf *fdf)
{
	if (key == KEY_R)
	{
		angle_init(&(fdf->mlx->handler), 0);
		if (fdf->mlx->handler.pro_mod == 0)
			++(fdf->mlx->handler.pro_mod);
		else
			fdf->mlx->handler.pro_mod = 0;
	}
	else if (key == KEY_1 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 0);
	else if (key == KEY_2 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 1);
	else if (key == KEY_3 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 2);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		terminate(fdf);
	else if (keycode == KEY_UP)
		(fdf->mlx->handler.mv_y) -= 30;
	else if (keycode == KEY_DOWN)
		(fdf->mlx->handler.mv_y) += 30;
	else if (keycode == KEY_LEFT)
		(fdf->mlx->handler.mv_x) -= 30;
	else if (keycode == KEY_RIGHT)
		(fdf->mlx->handler.mv_x) += 30;
	else if (keycode == KEY_ZM_U)
		(fdf->mlx->handler.scale) += fdf->mlx->handler.scale * 0.1;
	else if (keycode == KEY_ZM_D)
		(fdf->mlx->handler.scale) -= fdf->mlx->handler.scale * 0.1;
	else if (keycode == KEY_W)
		++(fdf->mlx->handler.angle_x);
	else if (keycode == KEY_S)
		--(fdf->mlx->handler.angle_x);
	else if (keycode == KEY_A)
		++(fdf->mlx->handler.angle_y);
	else if (keycode == KEY_Q)
		--(fdf->mlx->handler.angle_y);
	else if (keycode == KEY_E)
		++(fdf->mlx->handler.angle_z);
	else if (keycode == KEY_D)
		--(fdf->mlx->handler.angle_z);
	set_projection(keycode, fdf);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (button == 4 && fdf->mlx->handler.scale < 10000000)
		fdf->mlx->handler.scale += fdf->mlx->handler.scale * 0.1;
	else if (button == 5 && fdf->mlx->handler.scale > 0.0001)
		fdf->mlx->handler.scale -= fdf->mlx->handler.scale * 0.1;
	return (0);
}

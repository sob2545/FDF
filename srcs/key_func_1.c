/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:55:28 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 10:03:01 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>

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
	fdf->mlx->handler.key = keycode;
	if (keycode == KEY_ESC)
		terminate(fdf);
	if (keycode == KEY_F)
	{
		if (fdf->mlx->handler.line_mod == 0)
			++(fdf->mlx->handler.line_mod);
		else
			fdf->mlx->handler.line_mod = 0;
	}
	obj_init(keycode, fdf);
	obj_zoom(keycode, fdf);
	obj_move(keycode, fdf);
	obj_rotate(keycode, fdf);
	set_projection(keycode, fdf);
	return (0);
}

int	mouse_press(int btn, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (btn == 4 && fdf->mlx->handler.scale < 1000000)
		fdf->mlx->handler.scale += fdf->mlx->handler.scale * 0.1;
	else if (btn == 5 && fdf->mlx->handler.scale > 0.0001)
		fdf->mlx->handler.scale -= fdf->mlx->handler.scale * 0.1;
	return (0);
}

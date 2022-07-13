/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:55:28 by sesim             #+#    #+#             */
/*   Updated: 2022/07/13 15:42:46 by sesim            ###   ########.fr       */
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

void	set_projection(int key, t_fdf *fdf)
{
	int	j;
	int	k;

	if (key == KEY_P)
	{
		if (fdf->mlx->handler.pro_mod < 2)
			++(fdf->mlx->handler.pro_mod);
		else
			fdf->mlx->handler.pro_mod = 0;
	}
	else if (key == KEY_1)
		fdf->mlx->handler.view_pnt = 0;
	else if (key == KEY_2)
		fdf->mlx->handler.view_pnt = 1;
	else if (key == KEY_3)
		fdf->mlx->handler.view_pnt = 2;
	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
			view_point_init(&(fdf->point[j][k]), *(fdf->mlx), \
					fdf->mlx->handler.view_pnt);
	}
}

int	key_press(int keycode, t_fdf *fdf)
{
	fdf->mlx->handler.key = keycode;
	if (keycode == KEY_ESC)
		terminate(fdf);
	obj_init(keycode, fdf);
	obj_zoom(keycode, fdf);
	obj_move(keycode, fdf);
	obj_rotate(keycode, fdf);
	return (0);
}

int	mouse_press(int btn, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (btn == 4 && fdf->mlx->handler.scale < 1000)
		fdf->mlx->handler.scale *= 0.1;
	else if (btn == 5 && fdf->mlx->handler.scale > 0.0001)
		fdf->mlx->handler.scale *= 0.1;
	return (0);
}

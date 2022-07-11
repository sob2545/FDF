/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:55:28 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 12:58:00 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

void	terminate(t_fdf *fdf)
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
	free(fdf->mlx->img);
	free(fdf->mlx->mlx);
}

int	key_press_1(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		terminate(fdf);
	else if (keycode == KEY_UP)
}

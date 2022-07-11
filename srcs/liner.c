/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:06:24 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 18:24:51 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"

void	euler_rotate(t_fdf *fdf, int h, int w)
{
	rotate_z(h - (double)fdf->mlx->ucs.h / 2, w - (double)fdf->mlx->ucs.w / 2, \
			&fdf->point[h][w], fdf->mlx->handler.angle_z);
	rotate_y(fdf->point[h][w].iso_x, fdf->point[h][w].z, \
			&fdf->point[h][w], fdf->mlx->handler.angle_y);
	rotate_x(fdf->point[h][w].iso_y, fdf->point[h][w].ro_z, \
			&fdf->point[h][w], fdf->mlx->handler.angle_z);
}

void	rotation(t_fdf *fdf)
{
	int	j;
	int	k;

	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.ro_mod == 1)
				euler_rotate(fdf, j, k);
			else if (fdf->mlx->handler.ro_mod == 2)
				quaternion(fdf, j, k);
		}
	}
}

void	liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
		{
			fdf->
		}
	}
}

void	draw_liner(t_fdf *fdf)
{
	rotation(fdf);
	liner(fdf);
}

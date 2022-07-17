/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:00:25 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_fdf *fdf)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->mlx->ucs.h)
	{
		j = -1;
		while (++j < fdf->mlx->ucs.w)
		{
			x = j - (double)fdf->mlx->ucs.w / 2;
			y = i - (double)fdf->mlx->ucs.h / 2;
			rotate_z(x, y, &(fdf->point[i][j]), fdf->mlx->handler.angle_z);
			rotate_y(fdf->point[i][j].iso_x, fdf->point[i][j].z, \
					&fdf->point[i][j], fdf->mlx->handler.angle_y);
			rotate_x(fdf->point[i][j].iso_y, fdf->point[i][j].ro_z, \
					&fdf->point[i][j], fdf->mlx->handler.angle_x);
			projection(&fdf->point[i][j], fdf->mlx->handler);
		}
	}
}

void	bresen_line_1(t_fdf *fdf)
{
	t_vertex	line;
	int			i;
	int			j;

	i = -1;
	while (++i < fdf->mlx->ucs.h)
	{
		j = 0;
		while (++j < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[i][j - 1].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[i][j - 1].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[i][j].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[i][j].iso_y * fdf->mlx->handler.scale;
			line.color1 = fdf->point[i][j - 1].color;
			line.color2 = fdf->point[i][j].color;
			bresenham(line, fdf);
		}
	}
}

void	bresen_line_2(t_fdf *fdf)
{
	t_vertex	line;
	int			i;
	int			j;

	i = 0;
	while (++i < fdf->mlx->ucs.h)
	{
		j = -1;
		while (++j < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[i - 1][j].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[i - 1][j].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[i][j].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[i][j].iso_y * fdf->mlx->handler.scale;
			line.color1 = fdf->point[i - 1][j].color;
			line.color2 = fdf->point[i][j].color;
			bresenham(line, fdf);
		}
	}
}

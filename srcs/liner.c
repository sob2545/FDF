/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:06:24 by sesim             #+#    #+#             */
/*   Updated: 2022/07/16 22:29:10 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../libft/libft.h"

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
			rotate_z(k - fdf->mlx->ucs.w / 2, j - fdf->mlx->ucs.h / 2, \
				&fdf->point[j][k], fdf->mlx->handler.angle_z);
			rotate_y(fdf->point[j][k].iso_x, fdf->point[j][k].z, \
				&fdf->point[j][k], fdf->mlx->handler.angle_y);
			rotate_x(fdf->point[j][k].iso_y, fdf->point[j][k].ro_z, \
				&fdf->point[j][k], fdf->mlx->handler.angle_x);
			if (fdf->mlx->handler.pro_mod == 0)
				ft_isometric(&(fdf->point[j][k].iso_x), \
					&(fdf->point[j][k].iso_y), fdf->point[j][k].ro_z);
			else if (fdf->mlx->handler.pro_mod == 1)
				ft_parallel(&(fdf->point[j][k]));
		}
	}
}

void	bresen_liner(t_fdf *fdf)
{
	t_vertex	line;
	int	h;
	int	w;

	h = -1;
	while (++h < fdf->mlx->ucs.h)
	{
		w = 0;
		while (++w < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[h][w - 1].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[h][w - 1].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
			line.rgb1.color = fdf->point[h][w - 1].color;
			line.rgb2.color = fdf->point[h][w].color;
			bresenham(*(fdf->mlx), line);
		}
	}
	h = 0;
	while (++h < fdf->mlx->ucs.h)
	{
		w = -1;
		while (++w < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[h - 1][w].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[h - 1][w].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
			line.rgb1.color = fdf->point[h - 1][w].color;
			line.rgb2.color = fdf->point[h][w].color;
			bresenham(*(fdf->mlx), line);
		}
	}
}

void	anti_liner(t_fdf *fdf)
{
	t_vertex	line;
	int	h;
	int	w;

	h = -1;
	while (++h < fdf->mlx->ucs.h)
	{
		w = 0;
		while (++w < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[h][w - 1].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[h][w - 1].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
			line.rgb1.color = fdf->point[h][w - 1].color;
			line.rgb2.color = fdf->point[h][w].color;
			anti_alias(*(fdf->mlx), line);
		}
	}
	h = 0;
	while (++h < fdf->mlx->ucs.h)
	{
		w = -1;
		while (++w < fdf->mlx->ucs.w)
		{
			line.x1 = fdf->point[h - 1][w].iso_x * fdf->mlx->handler.scale;
			line.y1 = fdf->point[h - 1][w].iso_y * fdf->mlx->handler.scale;
			line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
			line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
			line.rgb1.color = fdf->point[h - 1][w].color;
			line.rgb2.color = fdf->point[h][w].color;
			anti_alias(*(fdf->mlx), line);
		}
	}
}

void	draw_liner(t_fdf *fdf)
{
	rotation(fdf);
	if (fdf->mlx->handler.line_mod == 0)
		bresen_liner(fdf);
	else if (fdf->mlx->handler.line_mod == 1)
		anti_liner(fdf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:06:24 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 13:48:21 by sesim            ###   ########.fr       */
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

t_vertex	set_vertex(t_fdf *fdf, int h, int w, int flag)
{
	t_vertex	line;

	ft_bzero(&line, sizeof(t_vertex));
	if (flag == 1)
	{
		line.x1 = fdf->point[h][w - 1].iso_x * fdf->mlx->handler.scale;
		line.y1 = fdf->point[h][w - 1].iso_y * fdf->mlx->handler.scale;
		line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
		line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
		line.rgb1.color = fdf->point[h][w - 1].color;
		line.rgb2.color = fdf->point[h][w].color;
	}
	else
	{
		line.x1 = fdf->point[h - 1][w].iso_x * fdf->mlx->handler.scale;
		line.y1 = fdf->point[h - 1][w].iso_y * fdf->mlx->handler.scale;
		line.x2 = fdf->point[h][w].iso_x * fdf->mlx->handler.scale;
		line.y2 = fdf->point[h][w].iso_y * fdf->mlx->handler.scale;
		line.rgb1.color = fdf->point[h - 1][w].color;
		line.rgb2.color = fdf->point[h][w].color;
	}
	return (line);
}

void	bresen_liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = 0;
		while (++k < fdf->mlx->ucs.w)
			bresenham(*(fdf->mlx), set_vertex(fdf, j, k, 1));
	}
	j = 0;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
			bresenham(*(fdf->mlx), set_vertex(fdf, j, k, 2));
	}
}

void	anti_liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = 0;
		while (++k < fdf->mlx->ucs.w)
			anti_alias(*(fdf->mlx), set_vertex(fdf, j, k, 1));
	}
	j = 0;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
			anti_alias(*(fdf->mlx), set_vertex(fdf, j, k, 2));
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

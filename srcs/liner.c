/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:06:24 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 13:10:21 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "liner.h"
#include "../libft/libft.h"

void	set_view(t_fdf *fdf, int h, int w)
{
	printf("%d\n", fdf->mlx->handler.pro_mod);
	if (fdf->mlx->handler.pro_mod == 0)
		ft_isometric(&(fdf->point[h][w].iso_x), &(fdf->point[h][w].iso_y), \
			fdf->point[h][w].ro_z);
	else if (fdf->mlx->handler.pro_mod == 1)
		ft_parallel(&(fdf->point[h][w]), *(fdf->mlx), \
			fdf->mlx->handler.view_pnt);
}

void	rotation(t_fdf *fdf)
{
	t_quater	q;
	int			j;
	int			k;

	ft_bzero(&q, sizeof(t_quater));
	q.w = 1.0;
	j = -1;
	printf("ro %d\n", fdf->mlx->handler.ro_mod);
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.ro_mod == 0)
				euler_rotate(fdf, j, k);
			/*else if (fdf->mlx->handler.ro_mod == 1)
				quaternion(fdf, &q, j, k);*/
			set_view(fdf, j, k);
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

void	x_liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = -1;
	while (++j < fdf->mlx->ucs.h)
	{
		k = 0;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.pro_mod == 0)
				bresenham(*(fdf->mlx), set_vertex(fdf, j, k, 1));
			else if (fdf->mlx->handler.pro_mod == 1)
				anti_alias(*(fdf->mlx), set_vertex(fdf, j, k, 1));
		}
	}
}

void	y_liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = 0;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.pro_mod == 0)
				bresenham(*(fdf->mlx), set_vertex(fdf, j, k, 2));
			else if (fdf->mlx->handler.pro_mod == 1)
				anti_alias(*(fdf->mlx), set_vertex(fdf, j, k, 2));
		}
	}
}

void	draw_liner(t_fdf *fdf)
{
	rotation(fdf);
	x_liner(fdf);
	y_liner(fdf);
}

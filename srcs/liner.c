/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:06:24 by sesim             #+#    #+#             */
/*   Updated: 2022/07/13 12:14:40 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../libft/libft.h"

void	set_view(t_fdf *fdf, int h, int w)
{
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

	j = -1;
	ft_bzero(&q, sizeof(t_quater));
	q.w = 1.0;
	while (++j < fdf->mlx->ucs.h)
	{
		k = -1;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.ro_mod == 0)
				euler_rotate(fdf, j, k);
			else if (fdf->mlx->handler.ro_mod == 1)
				quaternion(fdf, &q, j, k);
			set_view(fdf, j, k);
		}
	}
}

t_vertex	set_vertex(t_fdf *fdf, int h, int w)
{
	t_vertex	line;

	ft_bzero(&line, sizeof(t_vertex));
	line.x1 = fdf->point[h][w - 1].x;
	line.y1 = fdf->point[h][w - 1].y;
	line.x2 = fdf->point[h][w].y;
	line.y2 = fdf->point[h][w].y;
	line.rgb1.color = fdf->point[h][w - 1].color;
	line.rgb2.color = fdf->point[h][w].color;
	return (line);
}

void	liner(t_fdf *fdf)
{
	int	j;
	int	k;

	j = 0;
	while (++j < fdf->mlx->ucs.h)
	{
		k = 0;
		while (++k < fdf->mlx->ucs.w)
		{
			if (fdf->mlx->handler.pro_mod == 0)
				bresenham(*(fdf->mlx), set_vertex(fdf, j, k));
			else if (fdf->mlx->handler.pro_mod == 1)
				anti_alias(*(fdf->mlx), set_vertex(fdf, j, k));
		}
	}
}

void	draw_liner(t_fdf *fdf)
{
	rotation(fdf);
	liner(fdf);
}

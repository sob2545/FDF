/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:06:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 07:58:37 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include "fdf.h"

void	draw_x(t_fdf *fdf, t_vertex line, t_bresen_val val)
{
	while (val.x < line.x2)
	{
		if (val.init_val < 0)
			val.init_val += (2 * val.line_h);
		else
		{
			val.y += val.factor;
			val.init_val += 2 * (val.line_h - val.line_w);
		}
		if (check_win_size(val.x, val.y, fdf->mlx->handler.mv_x, \
				fdf->mlx->handler.mv_y) == 1)
			fdf->mlx->img->data[(WIN_W * (int)(val.y + fdf->mlx->handler.mv_y) \
				+ (int)val.x + (int)fdf->mlx->handler.mv_x)] = line.color2;
		val.x += 1;
	}
}

void	draw_y(t_fdf *fdf, t_vertex line, t_bresen_val val)
{
	while (val.y < line.y2)
	{
		if (val.init_val < 0)
			val.init_val += (2 * val.line_w);
		else
		{
			val.x += val.factor;
			val.init_val += 2 * (val.line_w - val.line_h);
		}
		if (check_win_size(val.x, val.y, fdf->mlx->handler.mv_x, \
				fdf->mlx->handler.mv_y) == 1)
			fdf->mlx->img->data[(WIN_W * (int)(val.y + fdf->mlx->handler.mv_y) \
				+ (int)val.x + (int)fdf->mlx->handler.mv_x)] = line.color2;
		val.y += 1;
	}
}

void	bresenham_x(t_vertex line, t_fdf *fdf)
{
	t_bresen_val	val;

	val.line_w = line.x2 - line.x1;
	val.line_h = line.y2 - line.y1;
	val.factor = 1;
	if (val.line_h < 0)
	{
		val.factor = -1;
		val.line_h *= -1;
	}
	val.x = line.x1;
	val.y = line.y1;
	val.init_val = 2 * val.line_h - val.line_w;
	draw_x(fdf, line, val);
}

void	bresenham_y(t_vertex line, t_fdf *fdf)
{
	t_bresen_val	val;

	val.line_w = line.x2 - line.x1;
	val.line_h = line.y2 - line.y1;
	val.factor = 1;
	if (val.line_w < 0)
	{
		val.factor = -1;
		val.line_w *= -1;
	}
	val.x = line.x1;
	val.y = line.y1;
	val.init_val = 2 * val.line_w - val.line_h;
	draw_y(fdf, line, val);
}

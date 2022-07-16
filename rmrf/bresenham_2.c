/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:06:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/17 00:35:17 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include "fdf.h"

int	set_gradient(t_vertex line, double grad)
{
	int	r;
	int	g;
	int	b;
	int	res;
	r = (line.rgb2.r - line.rgb1.r) * grad + line.rgb1.r;
	g = (line.rgb2.g - line.rgb1.g) * grad + line.rgb1.g;
	b = (line.rgb2.b - line.rgb1.b) * grad + line.rgb1.b;
	res = (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF);
	return (res);
}

void	draw_x(t_fdf *fdf, t_vertex line, t_bresen_val val)
{
	line.gradient = sqrt(pow(line.x2 - line.x1, 2) + pow(line.y2 - line.y1, 2));
	while (val.x < line.x2)
	{
		val.color = set_gradient(line, line.gradient);
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
				+ (int)val.x + (int)fdf->mlx->handler.mv_x)] = line.rgb2.color;
		val.x += 1;
	}
}

void	draw_y(t_fdf *fdf, t_vertex line, t_bresen_val val)
{
	line.gradient = sqrt(pow(line.x2 - line.x1, 2) + pow(line.y2 - line.y1, 2));
	while (val.y < line.y2)
	{
		val.color = set_gradient(line, line.gradient);
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
				+ (int)val.x + (int)fdf->mlx->handler.mv_x)] = line.rgb2.color;
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
	set_color(&line);
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
	set_color(&line);
	draw_y(fdf, line, val);
}

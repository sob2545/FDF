/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:21:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/17 00:52:04 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/libft.h"
#include "liner.h"
#include "../mlx/mlx.h"

void	draw_x(t_mlx mlx, t_vertex line, t_bresen_val *val)
{
	while (val->x < line.x2)
	{
		val->color = set_grad_color(&line, line.gradient);
		if (val->init_val < 0)
			val->init_val += (2 * val->line_h);
		else
		{
			val->y += val->factor;
			val->init_val += 2 * (val->line_h - val->line_w);
		}
		if ((int)val->x + (int)mlx.handler.mv_x >= 0 && (int)val->x + \
			(int)mlx.handler.mv_x < WIN_W && (WIN_W * (int)(val->y + \
			mlx.handler.mv_y) + (int)val->x + (int)mlx.handler.mv_x) >= 0 \
			&& (WIN_W * (int)(val->y + mlx.handler.mv_y) + (int)val->x + \
			(int)mlx.handler.mv_x < WIN_W * WIN_H))
			mlx.img->data[(WIN_W * (int)(val->y + mlx.handler.mv_y) + \
				(int)val->x + (int)mlx.handler.mv_x)] = line.rgb2.color;
		val->x += 1;
	}
}

void	draw_y(t_mlx mlx, t_vertex line, t_bresen_val *val)
{
	while (val->y < line.y2)
	{
		val->color = set_grad_color(&line, line.gradient);
		if (val->init_val < 0)
			val->init_val += (2 * val->line_w);
		else
		{
			val->x += val->factor;
			val->init_val += 2 * (val->line_w - val->line_h);
		}
		if ((int)val->x + (int)mlx.handler.mv_x >= 0 && (int)val->x + \
			(int)mlx.handler.mv_x < WIN_W && (WIN_W * (int)(val->y + \
			mlx.handler.mv_y) + (int)val->x + (int)mlx.handler.mv_x) >= 0 \
			&& (WIN_W * (int)(val->y + mlx.handler.mv_y) + (int)val->x + \
			(int)mlx.handler.mv_x < WIN_W * WIN_H))
			mlx.img->data[(WIN_W * (int)(val->y + mlx.handler.mv_y) + \
				(int)val->x + (int)mlx.handler.mv_x)] = line.rgb2.color;
		val->y += 1;
	}
}

void	bresenham_x(t_mlx mlx, t_vertex line)
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
	val.init_val = (2 * val.line_h) - val.line_w;
	draw_x(mlx, line, &val);
}

void	bresenham_y(t_mlx mlx, t_vertex line)
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
	val.init_val = (2 * val.line_w) - val.line_h;
	draw_y(mlx, line, &val);
}

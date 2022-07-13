/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:51:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/13 16:08:28 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"

void	middle_pixel_1(t_mlx mlx, t_vertex line, t_vertex pxl_point)
{
	int	i;
	int	x;
	int	y;

	i = pxl_point.x1 + 1;
	while (i < pxl_point.x2)
	{
		pxl_point.rgb1.color = set_grad(line.rgb1, \
			rev_dec_point(pxl_point.gradient));
		pxl_point.rgb2.color = set_grad(line.rgb2, \
			dec_point(pxl_point.gradient));
		x = i + mlx.ucs.h;
		y = dtoi(pxl_point.gradient) + mlx.ucs.w;
		if (check_win(x, y, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
		{
			mlx.img->data[(WIN_W * (int)(x + mlx.handler.mv_x) + y \
				+ (int)mlx.handler.mv_y)] = pxl_point.rgb1.color;
			mlx.img->data[(WIN_W * (int)(x + mlx.handler.mv_x) + y + 1 \
				+ (int)mlx.handler.mv_y)] = pxl_point.rgb2.color;
		}
		pxl_point.gradient += line.gradient;
		i++;
	}
}

void	middle_pixel_2(t_mlx mlx, t_vertex line, t_vertex pxl_point)
{
	int	i;
	int	x;
	int	y;

	i = pxl_point.y1 + 1;
	while (i < pxl_point.y2)
	{
		pxl_point.rgb1.color = set_grad(line.rgb1, \
			rev_dec_point(pxl_point.gradient));
		pxl_point.rgb2.color = set_grad(line.rgb2, \
			dec_point(pxl_point.gradient));
		x = dtoi(pxl_point.gradient) + mlx.ucs.w;
		y = i + mlx.ucs.h;
		if (check_win(x, y, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
		{
			mlx.img->data[(WIN_W * (int)(x + mlx.handler.mv_x) + y \
				+ (int)mlx.handler.mv_y)] = pxl_point.rgb1.color;
			mlx.img->data[(WIN_W * (int)(x + 1 + mlx.handler.mv_x) + y \
				+ (int)mlx.handler.mv_y)] = pxl_point.rgb2.color;
		}
		pxl_point.gradient += line.gradient;
		i++;
	}
}

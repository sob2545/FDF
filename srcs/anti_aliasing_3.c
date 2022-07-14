/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:51:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 13:09:06 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"

void	middle_pixel_1(t_mlx mlx, t_vertex line, t_vertex pxl_point)
{
	int	x;
	int	y;

	x = pxl_point.x1 + 1;
	while (x < pxl_point.x2)
	{
		pxl_point.rgb1.color = set_grad(line.rgb1, \
			rev_dec_point(pxl_point.gradient));
		pxl_point.rgb2.color = set_grad(line.rgb2, \
			dec_point(pxl_point.gradient));
		y = (int)(dtoi(pxl_point.gradient));
		if (check_win(x, y, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
			mlx.img->data[(WIN_W * (int)(y + mlx.handler.mv_y) + x \
				+ (int)mlx.handler.mv_x)] = pxl_point.rgb1.color;
		if (check_win(x, y + 1, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
			mlx.img->data[(WIN_W * (int)(y + mlx.handler.mv_y + 1) + x \
				+ (int)mlx.handler.mv_x)] = pxl_point.rgb2.color;
		pxl_point.gradient += line.gradient;
		x++;
	}
}

void	middle_pixel_2(t_mlx mlx, t_vertex line, t_vertex pxl_point)
{
	int	x;
	int	y;

	y = pxl_point.y1 + 1;
	while (y < pxl_point.y2)
	{
		pxl_point.rgb1.color = set_grad(line.rgb1, \
			rev_dec_point(pxl_point.gradient));
		pxl_point.rgb2.color = set_grad(line.rgb2, \
			dec_point(pxl_point.gradient));
		x = (int)(dtoi(pxl_point.gradient));
		if (check_win(x, y, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
			mlx.img->data[(WIN_W * (int)(y + mlx.handler.mv_y) + x \
				+ (int)mlx.handler.mv_x)] = pxl_point.rgb1.color;
		if (check_win(x + 1, y, mlx.handler.mv_x, mlx.handler.mv_y) == 1)
			mlx.img->data[(WIN_W * (int)(y + mlx.handler.mv_y) + x + 1 \
				+ (int)mlx.handler.mv_x)] = pxl_point.rgb2.color;
		pxl_point.gradient += line.gradient;
		y++;
	}
}

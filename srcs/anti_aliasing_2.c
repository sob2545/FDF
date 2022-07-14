/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:09:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 13:03:24 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../mlx/mlx.h"

void	first_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;

	end_x = ft_round(line.x1);
	end_y = line.y1 + line.gradient * (end_x - line.x1);
	gap = rev_dec_point(line.x1 + 0.5);
	pxl_point->x1 = end_x;
	pxl_point->y1 = dtoi(end_y);
	pxl_point->rgb1.color = set_grad(line.rgb1, rev_dec_point(end_y) * gap);
	pxl_point->rgb2.color = set_grad(line.rgb2, dec_point(end_y) * gap);
	if (check_win(pxl_point->x1, pxl_point->y1, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y1 + mlx.handler.mv_y) + \
			(int)pxl_point->x1 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb1.color;
	if (check_win(pxl_point->x1, pxl_point->y1 + 1, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y1 + 1 + mlx.handler.mv_y) + \
			(int)pxl_point->x1 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb2.color;
	pxl_point->gradient = end_y + line.gradient;
}

void	first_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;

	end_y = ft_round(line.y1);
	end_x = line.x1 + line.gradient * (end_y - line.y1);
	gap = rev_dec_point(line.y1 + 0.5);
	pxl_point->y1 = end_y;
	pxl_point->x1 = dtoi(end_x);
	pxl_point->rgb1.color = set_grad(line.rgb1, rev_dec_point(end_x) * gap);
	pxl_point->rgb2.color = set_grad(line.rgb2, dec_point(end_x) * gap);
	if (check_win(pxl_point->x1, pxl_point->y1, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y1 + mlx.handler.mv_y) + \
			(int)pxl_point->x1 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb1.color;
	if (check_win(pxl_point->x1 + 1, pxl_point->y1, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y1 + mlx.handler.mv_y) + \
			(int)pxl_point->x1 + 1 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb2.color;
	pxl_point->gradient = end_x + line.gradient;
}

void	last_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;

	end_x = ft_round(line.x2);
	end_y = line.y2 + line.gradient * (end_x - line.x2);
	gap = dec_point(line.x2 + 0.5);
	pxl_point->x2 = end_x;
	pxl_point->y2 = dtoi(end_y);
	pxl_point->rgb1.color = set_grad(line.rgb1, rev_dec_point(end_y) * gap);
	pxl_point->rgb2.color = set_grad(line.rgb2, dec_point(end_y) * gap);
	if (check_win(pxl_point->x2, pxl_point->y2, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y2 + mlx.handler.mv_y) + \
			(int)pxl_point->x2 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb1.color;
	if (check_win(pxl_point->x2, pxl_point->y2 + 1, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y2 + 1 + mlx.handler.mv_y) + \
			(int)pxl_point->x2 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb2.color;
}

void	last_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;

	end_y = ft_round(line.y2);
	end_x = line.x2 + line.gradient * (end_y - line.y2);
	gap = dec_point(line.y2 + 0.5);
	pxl_point->y2 = end_y;
	pxl_point->x2 = dtoi(end_x);
	pxl_point->rgb1.color = set_grad(line.rgb1, rev_dec_point(end_x) * gap);
	pxl_point->rgb2.color = set_grad(line.rgb2, dec_point(end_x) * gap);
	if (check_win(pxl_point->x2, pxl_point->y2, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y2 + mlx.handler.mv_y) + \
			(int)pxl_point->x2 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb1.color;
	if (check_win(pxl_point->x2 + 1, pxl_point->y2, mlx.handler.mv_x, \
		mlx.handler.mv_y) == 1)
		mlx.img->data[(WIN_W * (int)(pxl_point->y2 + mlx.handler.mv_y) + \
			(int)pxl_point->x2 + 1 + (int)mlx.handler.mv_x)] \
			= pxl_point->rgb2.color;
}

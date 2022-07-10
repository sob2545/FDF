/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:09:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/10 22:57:07 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anti_aliasing.h"
#include "../mlx/mlx.h"

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
	pxl_point->color1 = get_color(line.color1, rev_dec_point(end_y), gap);
	pxl_point->color2 = get_color(line.color2, dec_point(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.ucs.w, \
			pxl_point->y2 + mlx.ucs.h, pxl_point->color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.ucs.w, \
			pxl_point->y2 + 1 + mlx.ucs.h, pxl_point->color2);
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
	pxl_point->color1 = get_color(line.color1, rev_dec_point(end_x), gap);
	pxl_point->color2 = get_color(line.color2, dec_point(end_x), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.ucs.w, \
			pxl_point->y1 + mlx.ucs.h, pxl_point->color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + 1 + mlx.ucs.w, \
			pxl_point->y1 + mlx.ucs.h, pxl_point->color2);
	pxl_point->gradient = end_y + line.gradient;
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
	pxl_point->color1 = get_color(line.color1, rev_dec_point(end_x), gap);
	pxl_point->color2 = get_color(line.color2, dec_point(end_x), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.ucs.w, \
			pxl_point->y2 + mlx.ucs.h, pxl_point->color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + 1 + mlx.ucs.w, \
			pxl_point->y2 + mlx.ucs.h, pxl_point->color2);
}

void	middle_pixel_1(t_mlx mlx, t_vertex line, t_vertex pxl_point)
{
	int	i;
	int	x;
	int	y;

	i = pxl_point.x1 + 1;
	pxl_point.color1 = get_color(line.color1, \
			rev_dec_point(pxl_point.gradient), 1);
	pxl_point.color2 = get_color(line.color2, dec_point(pxl_point.gradient), 1);
	while (i < pxl_point.x2)
	{
		x = i + mlx.ucs.h;
		y = dtoi(pxl_point.gradient) + mlx.ucs.w;
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, pxl_point.color1);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y + 1, pxl_point.color2);
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
	pxl_point.color1 = get_color(line.color1, \
			rev_dec_point(pxl_point.gradient), 1);
	pxl_point.color2 = get_color(line.color2, dec_point(pxl_point.gradient), 1);
	while (i < pxl_point.y2)
	{
		x = dtoi(pxl_point.gradient) + mlx.ucs.w;
		y = i + mlx.ucs.h;
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, pxl_point.color1);
		mlx_pixel_put(mlx.mlx, mlx.win, x + 1, y, pxl_point.color2);
		pxl_point.gradient += line.gradient;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:10:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/10 22:56:54 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anti_aliasing.h"
#include "../mlx/mlx.h"
#include "math.h"

int	get_color(int color, double grad, double gap)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	rgb;

	t = (color >> 24) & 0xFF;
	r = ((color >> 16) & 0xFF) * grad * gap;
	g = ((color >> 8) & 0xFF) * grad * gap;
	b = (color & 0xFF) * grad * gap;
	rgb = 0;
	rgb |= t << 24;
	rgb |= r << 16;
	rgb |= g << 8;
	rgb |= b;
	return (rgb);
}

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
	pxl_point->color1 = get_color(line.color1, rev_dec_point(end_y), gap);
	pxl_point->color2 = get_color(line.color2, dec_point(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.ucs.w, \
			pxl_point->y1 + mlx.ucs.h, pxl_point->color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.ucs.w, \
			pxl_point->y1 + 1 + mlx.ucs.h, pxl_point->color2);
	pxl_point->gradient = end_y + line.gradient;
}

void	liner(t_mlx mlx, t_vertex line, int flag)
{
	t_vertex	pxl_point;

	if (flag == 1)
	{
		first_pixel_1(mlx, line, &pxl_point);
		last_pixel_1(mlx, line, &pxl_point);
		middle_pixel_1(mlx, line, pxl_point);
	}
	else
	{
		first_pixel_2(mlx, line, &pxl_point);
		last_pixel_2(mlx, line, &pxl_point);
		middle_pixel_2(mlx, line, pxl_point);
	}
}

void	check_steap(t_mlx mlx, t_vertex line, t_delta_val delta_val, int flag)
{
	if (flag == 1)
	{
		if (line.x2 < line.x1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
			ft_swap(&line.color1, &line.color2);
		}
		line.gradient = (delta_val.dy / delta_val.dx);
		liner(mlx, line, flag);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
			ft_swap(&line.color1, &line.color2);
		}
		line.gradient = (delta_val.dx / delta_val.dy);
		liner(mlx, line, flag);
	}
}

void	anti_alias(t_mlx mlx, t_vertex line)
{
	t_delta_val	delta_val;

	delta_val.dx = (double)line.x2 - (double)line.x1;
	delta_val.dy = (double)line.y2 - (double)line.y1;
	if (fabs(delta_val.dx) > fabs((delta_val.dy)))
		check_steap(mlx, line, delta_val, 1);
	else
		check_steap(mlx, line, delta_val, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:09:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/05 23:08:20 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx_macos/mlx.h"
#include <math.h>

void	first_pixel_1(t_mlx mlx, t_ptr line, t_ptr *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;
	unsigned int	color1;
	unsigned int	color2;

	end_x = ft_round(line.x1);
	end_y = line.y1 + line.gradient * (end_x - line.x1);
	gap = rev_dec_point(line.x1 + 0.5);
	pxl_point->x1 = end_x;
	pxl_point->y1 = dtoi(end_y);
	color1 = get_color(mlx, rev_dec_point(end_y), gap);
	color2 = get_color(mlx, dec_point(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.handler.delta_x, \
			pxl_point->y1 + mlx.handler.delta_y, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.handler.delta_x, \
			pxl_point->y1 + 1 + mlx.handler.delta_y, color2);
	pxl_point->gradient = end_y + line.gradient;
}

void	last_pixel_1(t_mlx mlx, t_ptr line, t_ptr *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;
	int		color1;
	int		color2;

	end_x = ft_round(line.x2);
	end_y = line.y2 + line.gradient * (end_x - line.x2);
	gap = dec_point(line.x2 + 0.5);
	pxl_point->x2 = end_x;
	pxl_point->y2 = dtoi(end_y);
	color1 = get_color(mlx, rev_dec_point(end_y), gap);
	color2 = get_color(mlx, dec_point(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.handler.delta_x, \
			pxl_point->y2 + mlx.handler.delta_y, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.handler.delta_x, \
			pxl_point->y2 + 1 + mlx.handler.delta_y, color2);
}

void	first_pixel_2(t_mlx mlx, t_ptr line, t_ptr *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;
	unsigned int		color1;
	unsigned int		color2;

	end_y = ft_round(line.y1);
	end_x = line.x1 + line.gradient * (end_y - line.y1);
	gap = rev_dec_point(line.y1 + 0.5);
	pxl_point->y1 = end_y;
	pxl_point->x1 = dtoi(end_x);
	color1 = get_color(mlx, rev_dec_point(end_x), gap);
	color2 = get_color(mlx, dec_point(end_x), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + mlx.handler.delta_x, \
			pxl_point->y1 + mlx.handler.delta_y, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x1 + 1 + mlx.handler.delta_x, \
			pxl_point->y1 + mlx.handler.delta_y, color2);
	pxl_point->gradient = end_x + line.gradient;
}

void	last_pixel_2(t_mlx mlx, t_ptr line, t_ptr *pxl_point)
{
	double	end_x;
	double	end_y;
	double	gap;
	unsigned int		color1;
	unsigned int		color2;

	end_y = ft_round(line.y2);
	end_x = line.x2 + line.gradient * (end_y - line.y2);
	gap = dec_point(line.y2 + 0.5);
	pxl_point->y2 = end_y;
	pxl_point->x2 = dtoi(end_x);
	color1 = get_color(mlx, rev_dec_point(end_x), gap);
	color2 = get_color(mlx, dec_point(end_x), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + mlx.handler.delta_x, \
			pxl_point->y2 + mlx.handler.delta_y, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxl_point->x2 + 1 + mlx.handler.delta_x, \
			pxl_point->y2 + mlx.handler.delta_y, color2);
}

void	middle_pixel_1(t_mlx mlx, t_ptr line, t_ptr pxl_point)
{
	unsigned int	color1;
	unsigned int	color2;
	int	i;
	int	x;
	int	y;

	i = pxl_point.x1 + 1;
	while (i < pxl_point.x2)
	{
		color1 = get_color(mlx, rev_dec_point(pxl_point.gradient), 1);
		color2 = get_color(mlx, dec_point(pxl_point.gradient), 1);
		x = i + mlx.handler.delta_x;
		y = dtoi(pxl_point.gradient) + mlx.handler.delta_y;
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, color1);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y + 1, color2);
		pxl_point.gradient += line.gradient;
		i++;
	}
}

void	middle_pixel_2(t_mlx mlx, t_ptr line, t_ptr pxl_point)
{
	unsigned int	color1;
	unsigned int	color2;
	int	i;
	int	x;
	int	y;

	i = pxl_point.y1 + 1;
	while (i < pxl_point.y2)
	{
		color1 = get_color(mlx, rev_dec_point(pxl_point.gradient), 1);
		color2 = get_color(mlx, dec_point(pxl_point.gradient), 1);
		y = i + mlx.handler.delta_y;
		x = dtoi(pxl_point.gradient) + mlx.handler.delta_x;
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, color1);
		mlx_pixel_put(mlx.mlx, mlx.win, x + 1, y, color2);
		pxl_point.gradient += line.gradient;
		i++;
	}
}

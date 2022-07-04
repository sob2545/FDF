/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:10:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/04 10:10:17 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx_macos/mlx.h"
#include "math.h"

int	get_color(t_mlx mlx, double grad, double gap)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	rgb;

	t = (mlx.handler.color >> 24) & 0xFF;
	r = ((mlx.handler.color >> 16) & 0xFF) * grad * gap;
	g = ((mlx.handler.color >> 8) & 0xFF) * grad * gap;
	b = (mlx.handler.color & 0xFF) * grad * gap;
	rgb = 0;
	rgb |= t << 24;
	rgb |= r << 16;
	rgb |= g << 8;
	rgb |= b;
	return (rgb);
}

void	liner(t_mlx mlx, t_ptr line, t_ptr *pxl_point, int flag)
{
	if (flag == 1)
	{
		first_pixel_1(mlx, line, pxl_point);
		last_pixel_1(mlx, line, pxl_point);
		middle_pixel(mlx, line, *pxl_point, 1);
	}
	else
	{
		first_pixel_2(mlx, line, pxl_point);
		last_pixel_2(mlx, line, pxl_point);
		middle_pixel(mlx, line, *pxl_point, 2);
	}
}

void	anti_alias(t_mlx mlx, t_ptr line)
{
	t_ptr	pxl_point;

	if (fabs((double)line.x2) < fabs((double)line.x1))
	{
		if (line.x2 < line.x1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = ((double)line.x2 - (double)line.x1 / \
				(double)line.y2 - (double)line.y1);
		liner(mlx, line, &pxl_point, 1);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = ((double)line.y2 - (double)line.y1 / \
				(double)line.x2 - (double)line.x1);
		liner(mlx, line, &pxl_point, 2);
	}
}

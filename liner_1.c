/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:10:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/04 22:01:34 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./mlx/mlx.h"
#include "math.h"

int	get_color(t_mlx mlx, double grad, double gap)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	rgb;

	t = (mlx.ucs.color >> 24) & 0xFF;
	r = ((mlx.ucs.color >> 16) & 0xFF) * grad * gap;
	g = ((mlx.ucs.color >> 8) & 0xFF) * grad * gap;
	b = (mlx.ucs.color & 0xFF) * grad * gap;
	rgb = 0;
	rgb |= t << 24;
	rgb |= r << 16;
	rgb |= g << 8;
	rgb |= b;
	return (rgb);
}

void	liner(t_mlx mlx, t_ptr line, int flag)
{
	t_ptr	pxl_point;

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

void	anti_alias(t_mlx mlx, t_ptr line)
{
	t_delta_val	delta_val;

	delta_val.dx = line.x2 - line.x1;
	delta_val.dy = line.y2 - line.y1;
	if (fabs(delta_val.dx) < fabs((delta_val.dy)))
	{
		if (line.x2 < line.x1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = (delta_val.dy / delta_val.dx);
		liner(mlx, line, 1);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = (delta_val.dx / delta_val.dy);
		liner(mlx, line, 2);
	}
}

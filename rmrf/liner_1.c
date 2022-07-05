/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:10:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/05 23:09:51 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../minilibx_macos/mlx.h"
#include "math.h"

unsigned int	get_color(t_mlx mlx, double grad, double gap)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	rgb;

	t = (mlx.handler.color >> 24) & 0xFF;
	r = ((mlx.handler.color >> 16) & 0xFF) * fabs(grad * gap);
	g = ((mlx.handler.color >> 8) & 0xFF) * fabs(grad * gap);
	b = (mlx.handler.color & 0xFF) * fabs(grad * gap);
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

	delta_val.w = line.x2 - line.x1;
	delta_val.h = line.y2 - line.y1;
	if (fabs(delta_val.w) > fabs(delta_val.h))
	{
		if (line.x2 < line.x1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = delta_val.h / delta_val.w;
		liner(mlx, line, 1);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = delta_val.w / delta_val.h;
		liner(mlx, line, 2);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:10:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/17 00:48:17 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../mlx/mlx.h"
#include "math.h"

int	set_grad(t_rgb color, double grad)
{
	int	t;
	int	rgb;

	t = 0xFF - (0xFF * grad);
	rgb = 0;
	rgb |= (t & 0xFF) << 24;
	rgb |= color.r << 16;
	rgb |= color.g << 8;
	rgb |= color.b;
	return (rgb);
}

static void	liner(t_mlx mlx, t_vertex line, int flag)
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

static void	check_steap(t_mlx mlx, t_vertex line, t_delta_val delta_val, int f)
{
	if (f == 1)
	{
		if (line.x2 < line.x1)
		{
			double_swap(&line.x2, &line.x1);
			double_swap(&line.y2, &line.y1);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		line.gradient = (delta_val.dy / delta_val.dx);
		set_color(&line);
		liner(mlx, line, f);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			double_swap(&line.x2, &line.x1);
			double_swap(&line.y2, &line.y1);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		line.gradient = (delta_val.dx / delta_val.dy);
		set_color(&line);
		liner(mlx, line, f);
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

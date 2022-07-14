/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:21:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 08:17:18 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/libft.h"
#include "liner.h"
#include "../mlx/mlx.h"

int	set_grad_color(t_vertex *line, double grad)
{
	int	rgb;
	int	r;
	int	g;
	int	b;

	r = (line->rgb2.r - line->rgb1.r) * grad + line->rgb1.r;
	g = (line->rgb2.g - line->rgb1.g) * grad + line->rgb1.g;
	b = (line->rgb2.b - line->rgb1.b) * grad + line->rgb1.b;
	rgb = 0;
	rgb |= (r & 0xFF) << 16;
	rgb |= (g & 0xFF) << 8;
	rgb |= b & 0xFF;
	return (rgb);
}

void	set_color(t_vertex *line)
{
	line->rgb1.a |= (line->rgb1.color >> 24) & 0xFF;
	line->rgb1.r |= (line->rgb1.color >> 16) & 0xFF;
	line->rgb1.g |= (line->rgb1.color >> 8) & 0xFF;
	line->rgb1.b |= line->rgb1.color & 0xFF;
	line->rgb2.a |= (line->rgb2.color >> 24) & 0xFF;
	line->rgb2.r |= (line->rgb2.color >> 16) & 0xFF;
	line->rgb2.g |= (line->rgb2.color >> 8) & 0xFF;
	line->rgb2.b |= line->rgb2.color & 0xFF;
}

static void	check_steap(t_mlx mlx, t_vertex line, t_delta_val delta_val, int f)
{
	line.gradient = sqrt(pow(delta_val.dx, 2) + pow(delta_val.dy, 2));
	if (f == 1)
	{
		if (line.x2 < line.x1)
		{
			double_swap(&line.x2, &line.x1);
			double_swap(&line.y2, &line.y1);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		set_color(&line);
		bresenham_x(mlx, line);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			double_swap(&line.x2, &line.x1);
			double_swap(&line.y2, &line.y1);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		set_color(&line);
		bresenham_y(mlx, line);
	}
}

void	bresenham(t_mlx mlx, t_vertex line)
{
	t_delta_val	delta_val;

	delta_val.dx = fabs((double)line.x2 - (double)line.x1);
	delta_val.dy = fabs((double)line.y2 - (double)line.y1);
	if (delta_val.dx > delta_val.dy)
		check_steap(mlx, line, delta_val, 1);
	else
		check_steap(mlx, line, delta_val, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:06:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/17 00:37:17 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include "fdf.h"

void	double_swap(double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	color_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	set_color(t_vertex *line)
{
	line->rgb1.a |= (line->rgb1.color >> 24) & 0xFF;
	line->rgb1.r |= (line->rgb1.color >> 16) & 0xFF;
	line->rgb1.g |= (line->rgb1.color >> 8) & 0xFF;
	line->rgb1.b |= line->rgb1.color & 0xFF;
	line->rgb2.a |= (line->rgb1.color >> 24) & 0xFF;
	line->rgb2.r |= (line->rgb1.color >> 16) & 0xFF;
	line->rgb2.g |= (line->rgb1.color >> 8) & 0xFF;
	line->rgb2.b |= line->rgb1.color & 0xFF;
}

int	check_win_size(double x, double y, double mv_x, double mv_y)
{
	if ((int)x + (int)mv_x >= 0 && (int)x + (int)mv_x < WIN_W && \
		(WIN_W * (int)(y + mv_y) + (int)x + (int)mv_x) >= 0 \
		&& (WIN_W * (int)(y + mv_y) + (int)x + (int)mv_x < WIN_W * WIN_H))
		return (1);
	else
		return (0);
}

void	bresenham(t_vertex line, t_fdf *fdf)
{
	t_delta_val	delta_val;

	delta_val.dx = fabs(line.x2 - line.x1);
	delta_val.dy = fabs(line.y2 - line.y1);
	if (delta_val.dx > delta_val.dy)
	{
		if (line.x1 > line.x2)
		{
			double_swap(&line.x1, &line.x2);
			double_swap(&line.y1, &line.y2);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		bresenham_x(line, fdf);
	}
	else
	{
		if (line.y1 > line.y2)
		{
			double_swap(&line.x1, &line.x2);
			double_swap(&line.y1, &line.y2);
			color_swap(&line.rgb1.color, &line.rgb2.color);
		}
		bresenham_y(line, fdf);
	}
}

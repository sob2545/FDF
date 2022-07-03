/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:06:25 by sesim             #+#    #+#             */
/*   Updated: 2022/07/03 18:00:41 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./mlx/mlx.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

double	ft_abs(double value)
{
	if (value > 0)
		return (value);
	else
		return (-1 * value);
}

int	dtoi(double val)
{
	return ((int)val);
}

int	ft_round(double val)
{
	return ((int)((double)(val) +0.5));
}

double	decPoint(double val)
{
	return ((double)(val) - (dtoi(val)));
}

double	rev_decPoint(double val)
{
	return (1.0 - decPoint(val));
}

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

void	first_pixel(t_mlx mlx, t_ptr line, t_ptr *pxlPoint)
{
	double	end_x;
	double	end_y;
	double	gap;
	int		color1;
	int		color2;

	end_x = ft_round(line.x1);
	end_y = line.y1 + line.gradient * (end_x - line.x1);
	gap = rev_decPoint(line.x1 + 0.5);
	pxlPoint->x1 = end_x;
	pxlPoint->y1 = dtoi(end_y);
	color1 = get_color(mlx, rev_decPoint(end_y), gap);
	color2 = get_color(mlx, decPoint(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxlPoint->x1 + mlx.ucs.w, pxlPoint->y1 + mlx.ucs.h, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxlPoint->x1 + mlx.ucs.w, pxlPoint->y1 + 1 + mlx.ucs.h, color2);
	pxlPoint->gradient = end_y + line.gradient;
}

void	last_pixel(t_mlx mlx, t_ptr line, t_ptr *pxlPoint)
{
	double	end_x;
	double	end_y;
	double	gap;
	int		color1;
	int		color2;

	end_x = ft_round(line.x2);
	end_y = line.y2 + line.gradient * (end_x - line.x2);
	gap = decPoint(line.x2 + 0.5);
	pxlPoint->x2 = end_x;
	pxlPoint->y2 = dtoi(end_y);
	color1 = get_color(mlx, rev_decPoint(end_y), gap);
	color2 = get_color(mlx, decPoint(end_y), gap);
	mlx_pixel_put(mlx.mlx, mlx.win, pxlPoint->x2 + mlx.ucs.w, pxlPoint->y2 + mlx.ucs.h, color1);
	mlx_pixel_put(mlx.mlx, mlx.win, pxlPoint->x2 + mlx.ucs.w, pxlPoint->y2 + 1 + mlx.ucs.h, color2);
}

void	middle_pixel(t_mlx mlx, t_ptr line, t_ptr pxlPoint, int flag)
{
	int	color1;
	int	color2;
	int	i;
	int	x;
	int	y;

	i = 0;
	color1 = get_color(mlx, rev_decPoint(pxlPoint.gradient), 1);
	color2 = get_color(mlx, decPoint(pxlPoint.gradient), 1);
	while (i < pxlPoint.y1)
	{
		x = i + mlx.ucs.h;
		y = dtoi(pxlPoint.gradient) + mlx.ucs.w;
		if (flag == 2)
			ft_swap(&x, &y);
		mlx_pixel_put(mlx.mlx, mlx.win, x, y, color1);
		if (flag == 1)
			mlx_pixel_put(mlx.mlx, mlx.win, x, y + 1, color2);
		else
			mlx_pixel_put(mlx.mlx, mlx.win, x + 1, y, color2);
		pxlPoint.gradient += line.gradient;
		i++;
	}
}

void	anti_alias(t_mlx mlx, t_ptr line)
{
	t_ptr	pxlPoint;

	if (ft_abs(line.x2) < ft_abs(line.x1))
	{
		if (line.x2 < line.x1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = ((double)line.x2 - (double)line.x1 / (double)line.y2 - (double)line.y1);
		first_pixel(mlx, line, &pxlPoint);
		last_pixel(mlx, line, &pxlPoint);
		middle_pixel(mlx, line, pxlPoint, 1);
	}
	else
	{
		if (line.y2 < line.y1)
		{
			ft_swap(&line.x2, &line.x1);
			ft_swap(&line.y2, &line.y1);
		}
		line.gradient = ((double)line.y2 - (double)line.y1 / (double)line.x2 - (double)line.x1);
		first_pixel(mlx, line, &pxlPoint);
		last_pixel(mlx, line, &pxlPoint);
		middle_pixel(mlx, line, pxlPoint, 2);
	}
}

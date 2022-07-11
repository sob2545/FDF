/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:21:08 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 15:58:49 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

void	bresenham_x(double start_x, double start_y, double finish_x, double finish_y, t_all *all)
{
	double width;
	double height;
	double	x;
	double	y;
	double	formula;
	double Yfactor;

	width = finish_x - start_x;
	height = finish_y - start_y;
	Yfactor = 1;
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	while (x < finish_x)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			y += Yfactor;
			formula += 2 * (height - width);
		}
		if ((int)x + (int)all->mlx->handler.delta_x < 0 || (int)x + (int)all->mlx->handler.delta_x >= 1600 \
			|| (1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) < 0 \
			|| (1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) > 1600 * 900)

		{
			x+= 1;
			continue ;
		}
		all->img->data[(1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x)] = 0xFFFFFF;
		x += 1;
	}
}

void	bresenham_y(double start_x, double start_y, double finish_x, double finish_y, t_all *all)
{
	double width;
	double height;
	double	x;
	double	y;
	double	formula;
	double Xfactor;
	width = finish_x - start_x;
	height = finish_y - start_y;
	Xfactor = 1;
	if (width < 0)
	{
		Xfactor = -1;
		width *= -1;
	}

	x = start_x;
	y = start_y;
	formula = 2 * width - height;
	while (y < finish_y)
	{
		if (formula < 0)
			formula += (2 * width);
		else
		{
			x += Xfactor;
			formula += 2 * (width - height);
		}
		// x 계산값이 윈도우 범위를 넘어서면 화면에 표시하지 않는다 / data에 접근하는 인덱스값 이 음수이면 배열에 접근하지 않는다
		// if ((int)(y + all->mlx->handler.delta_y) > 900)
		// 	return ;
		if ((int)x + (int)all->mlx->handler.delta_x < 0 || (int)x + (int)all->mlx->handler.delta_x >= 1600 \
			|| (int)(y + all->mlx->handler.delta_y) > 900 || \
			(1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) < 0 \
			|| (1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) > 1600 * 900)
		{
			y += 1;
			continue;
		}
		// if ((int)x + (int)all->mlx->handler.delta_x > 0 || (int)x + (int)all->mlx->handler.delta_x < 1600 \
		// 	|| (int)(y + all->mlx->handler.delta_y) < 900 || \
		// 	(1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) > 0 \
		// 	|| (1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x) < 1600 * 900)
		// {
		// 	all->img->data[(1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x)] = 0x00FF00;
		// }
		all->img->data[(1600 * (int)(y + all->mlx->handler.delta_y) + (int)x + (int)all->mlx->handler.delta_x)] = 0x00FF00;
		y += 1;
	}
}

void	bresenham(t_mlx mlx, t_vertex line)
{
	t_delta_val delta_val;

	delta_val.dx = (double)line.x2 - (double)line.x1;
	if (width < 0)
		width *= -1;
	if (height < 0)
		height *= -1;
	if (width > height)
	{
		if (start_x > finish_x)
			bresenham_x(finish_x, finish_y, start_x, start_y, all);
		else
			bresenham_x(start_x, start_y, finish_x, finish_y, all);
	}
	else
	{
		if (start_y > finish_y)
			bresenham_y(finish_x, finish_y, start_x, start_y, all);
		else
			bresenham_y(start_x, start_y, finish_x, finish_y, all);
	}
}

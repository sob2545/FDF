/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:02:40 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 11:55:48 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "liner.h"

{
	static t_quaternion	prev_q;
	t_quaternion		*q = (t_quaternion *)param;

	if (memcmp(q, &prev_q, sizeof(t_quaternion)))
	{
		prev_q = *q;
		calc_quaternion(q);
		draw(*q);
		return (1);
	}
	return (0);
}

void	draw_vector(t_point p, int color)
{
	double	dt = fmax(fabs(p.y), fabs(p.z));
	double	dx = p.y / dt, dy = p.z / dt;
	double	x = (double)SCREEN_WIDTH / 2, y = (double)SCREEN_HEIGHT / 2;
	for (double i=0; i<=dt; i+=1.0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color);
		x += dx;
		y -= dy;
	}
}

void	cal_quater(t_quater *q, t_fdf *fdf, int w, int h)
{
	t_quater_param	param;

	param.w_x = q->w * q->x;
	param.w_y = q->w * q->y;
	param.w_z = q->w * q->z;
	param.x_pow = q->x * q->x;
	param.y_pow = q->y * q->y;
	param.z_pow = q->z * q->z;
	param.x_y = q->x * q->y;
	param.x_z = q->x * q->z;
	param.y_z = q->y * q->z;
	fdf->point[h][w].iso_x = fdf->point[h][w].x * (1. - 2. * param.y_pow - 2. \
		* param.z_pow) + fdf->point[h][w].y * (2. * param.x_y - 2. * \
		param.w_z) + fdf->point[h][w].z * (2. * param.x_z + 2. * param.w_y);
	fdf->point[h][w].iso_y = fdf->point[h][w].x * (2. * param.x_y + 2. * \
		param.w_z) + fdf->point[h][w].y * (1. - 2. * param.x_pow - 2. * \
		param.z_pow) + fdf->point[h][w].z * (2. * param.y_z - 2. * param.w_x);
	fdf->point[h][w].ro_z = fdf->point[h][w].x * (2. * param.x_z - 2. * \
		param.w_y) + fdf->point[h][w].y * (2. * param.y_z + 2. * param.w_x) \
		+ fdf->point[h][w].z * (1. - 2. * param.x_pow - 2. * param.y_pow);
}

void	draw(t_quater q, t_fdf *fdf, int x, int y)
{

}

void	draw_axis(t_quater q, t_fdf *fdf, int x, int y)
{
	t_quater	x_axis;
	t_quater	y_axis;
	t_quater	z_axis;

	ft_bzero(&x_axis, sizeof(t_quater));
	x_axis.x = x;
	ft_bzero(&y_axis, sizeof(t_quater));
	y_axis.x = y;
	ft_bzero(&z_axis, sizeof(t_quater));
	z_axis.x = fdf->point[y][x].z;
	calc_quaternion(x_axis, q, fdf);
	calc_quaternion(y_axis, q, fdf);
	calc_quaternion(z_axis, q, fdf);
}

void	quaternion(t_fdf *fdf)
{
	t_quater	q;

	ft_bzero(q, sizeof(t_quater));
	q.w = 1.0;
}

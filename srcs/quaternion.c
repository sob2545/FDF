/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:09:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/13 10:44:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

void	quaternion_cal(t_fdf *fdf, t_quater *q, int h, int w)
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

void	quaternion_ro(t_quater *q, t_quater angle)
{
	double	w;
	double	x;
	double	y;
	double	z;

	w = (angle.w * q->w) - (angle.x * q->x) - \
		(angle.y * q->y) - (angle.z * q->z);
	x = (angle.x * q->w) - (angle.w * q->x) - \
		(angle.z * q->y) - (angle.y * q->z);
	y = (angle.y * q->w) - (angle.z * q->x) - \
		(angle.w * q->y) - (angle.x * q->z);
	z = (angle.z * q->w) - (angle.y * q->x) - \
		(angle.x * q->y) - (angle.w * q->z);
	q->w = w;
	q->x = x;
	q->y = y;
	q->z = z;
}

void	quaternion(t_fdf *fdf, t_quater *q, int h, int w)
{
	t_quater	angle;

	ft_bzero(&angle, sizeof(t_quater));
	if (fdf->mlx->handler.key == KEY_A)
		set_quater_angle_x(fdf, &angle, 1);
	else if (fdf->mlx->handler.key == KEY_D)
		set_quater_angle_x(fdf, &angle, 2);
	else if (fdf->mlx->handler.key == KEY_W)
		set_quater_angle_y(fdf, &angle, 1);
	else if (fdf->mlx->handler.key == KEY_S)
		set_quater_angle_y(fdf, &angle, 2);
	else if (fdf->mlx->handler.key == KEY_Q)
		set_quater_angle_z(fdf, &angle, 1);
	else if (fdf->mlx->handler.key == KEY_E)
		set_quater_angle_z(fdf, &angle, 2);
	quaternion_ro(q, angle);
	quaternion_cal(fdf, q, h, w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:09:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/12 16:22:35 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

void	rotate_x(double y, double z, t_point *point, double angle)
{
	double	pi;

	pi = M_PI / 180;
	point->iso_y = y * cos(angle * pi) + (z) * sin(angle * pi);
	point->ro_z = -y * sin(angle * pi) + (z) * cos(angle * pi);
}

void	rotate_y(double x, double z, t_point *point, double angle)
{
	double	pi;

	pi = M_PI / 180;
	point->iso_x = x * cos(angle * pi) + (z) * sin(angle * pi);
	point->ro_z = -x * sin(angle * pi) + (z) * cos(angle * pi);
}

void	rotate_z(double x, double y, t_point *point, double angle)
{
	double	pi;

	pi = M_PI / 180;
	point->iso_x = x * cos(angle * pi) - y * sin(angle * pi);
	point->iso_y = x * sin(angle * pi) + y * cos(angle * pi);
}

void	quaternion(t_fdf *fdf, t_quater *q, int h, int w)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:09:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/13 08:13:30 by sesim            ###   ########.fr       */
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

void	euler_rotate(t_fdf *fdf, int h, int w)
{
	rotate_z(h - (double)fdf->mlx->ucs.h / 2, w - (double)fdf->mlx->ucs.w / 2, \
			&fdf->point[h][w], fdf->mlx->handler.angle_z);
	rotate_y(fdf->point[h][w].iso_x, fdf->point[h][w].z, \
			&fdf->point[h][w], fdf->mlx->handler.angle_y);
	rotate_x(fdf->point[h][w].iso_y, fdf->point[h][w].ro_z, \
			&fdf->point[h][w], fdf->mlx->handler.angle_z);
}

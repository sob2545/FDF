/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:09:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/12 23:41:31 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <math.h>

void	set_quater_angle_x(t_fdf *fdf, t_quater *angle, int flag)
{
	if (flag == 1)
	{
		angle->w = cos(fdf->mlx->handler.angle_x * M_PI / 180);
		angle->x = sin(fdf->mlx->handler.angle_x * M_PI / 180);
	}
	else
	{
		angle->w = cos(fdf->mlx->handler.angle_x * M_PI / 180);
		angle->x = -sin(fdf->mlx->handler.angle_x * M_PI / 180);
	}
}

void	set_quater_angle_y(t_fdf *fdf, t_quater *angle, int flag)
{
	if (flag == 1)
	{
		angle->w = cos(fdf->mlx->handler.angle_y * M_PI / 180);
		angle->y = sin(fdf->mlx->handler.angle_y * M_PI / 180);
	}
	else
	{
		angle->w = cos(fdf->mlx->handler.angle_y * M_PI / 180);
		angle->y = -sin(fdf->mlx->handler.angle_y * M_PI / 180);
	}
}

void	set_quater_angle_z(t_fdf *fdf, t_quater *angle, int flag)
{
	if (flag == 1)
	{
		angle->w = cos(fdf->mlx->handler.angle_z * M_PI / 180);
		angle->z = sin(fdf->mlx->handler.angle_z * M_PI / 180);
	}
	else
	{
		angle->w = cos(fdf->mlx->handler.angle_z * M_PI / 180);
		angle->z = -sin(fdf->mlx->handler.angle_z * M_PI / 180);
	}
}

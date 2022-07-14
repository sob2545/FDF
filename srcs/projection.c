/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:09:13 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 09:03:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include <math.h>

void	view_point_init(t_point *point, t_mlx mlx, int mod)
{
	if (mod == 0)
	{
		point->iso_x = point->x - (mlx.ucs.w / 2);
		point->iso_y = point->y - (mlx.ucs.h / 2);
	}
	if (mod == 1)
	{
		point->iso_x = point->x - (mlx.ucs.w / 2);
		point->iso_y = ((point->z) * -1) - (point->z / 2);
	}
	else if (mod == 2)
	{
		point->iso_x = point->y - (mlx.ucs.h / 2);
		point->iso_y = ((point->z) * -1) - (point->z / 2);
	}
}

void	ft_parallel(t_point *point, t_mlx mlx, int mod)
{
	double	x;
	double	y;
	double	z;

	x = point->iso_y;
	y = point->iso_y;
	z = point->ro_z;
	if (mod == 0)
	{
		point->iso_x = x - (mlx.ucs.w / 2);
		point->iso_y = y - (mlx.ucs.h / 2);
	}
	if (mod == 1)
	{
		point->iso_x = x - (mlx.ucs.w / 2);
		point->iso_y = (z * -1) - (point->z / 2);
	}
	else if (mod == 2)
	{
		point->iso_x = y - (mlx.ucs.h / 2);
		point->iso_y = (z * -1) - (point->z / 2);
	}
}

void	ft_isometric(double *x, double *y, double z)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(M_PI / 6);
	*y = (prev_x + prev_y) * cos(M_PI / 3) - z;
}

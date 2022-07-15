/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:09:59 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 08:27:46 by sesim            ###   ########.fr       */
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
	point->iso_y = y * cos(angle * pi) + z * sin(angle * pi);
	point->ro_z = -y * sin(angle * pi) + z * cos(angle * pi);
}

void	rotate_y(double x, double z, t_point *point, double angle)
{
	double	pi;

	pi = M_PI / 180;
	point->iso_x = x * cos(angle * pi) + z * sin(angle * pi);
	point->ro_z = -x * sin(angle * pi) + z * cos(angle * pi);
}

void	rotate_z(double x, double y, t_point *point, double angle)
{
	double	pi;

	pi = M_PI / 180;
	point->iso_x = x * cos(angle * pi) - y * sin(angle * pi);
	point->iso_y = x * sin(angle * pi) + y * cos(angle * pi);
}

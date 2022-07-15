/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:09:13 by sesim             #+#    #+#             */
/*   Updated: 2022/07/15 09:47:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"
#include <math.h>

void	ft_parallel(t_point *point)
{
	double	x;
	double	y;

	x = point->iso_x;
	y = point->iso_y;
	point->iso_x = x;
	point->iso_y = y;
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

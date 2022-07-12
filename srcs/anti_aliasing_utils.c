/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:42 by sesim             #+#    #+#             */
/*   Updated: 2022/07/12 10:38:44 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liner.h"

int	check_win(double x, double y, double mv_x, double mv_y)
{
	if ((int)x + (int)mv_x < 0 || (int)x + (int)mv_x >= WIN_W || \
		(WIN_W * (int)(y + mv_y) + (int)x + (int)mv_x) < 0 || \
		(WIN_W * (int)(y + mv_y) + (int)x + (int)mv_x) > WIN_W * WIN_H)
		return (1);
	else
		return (0);
}

int	dtoi(double val)
{
	return ((int)val);
}

int	ft_round(double val)
{
	return ((int)((double)(val) +0.5));
}

double	dec_point(double val)
{
	return ((double)(val) - (dtoi(val)));
}

double	rev_dec_point(double val)
{
	return (1.0 - dec_point(val));
}

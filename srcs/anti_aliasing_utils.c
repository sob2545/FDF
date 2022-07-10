/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:11:42 by sesim             #+#    #+#             */
/*   Updated: 2022/07/10 22:57:24 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "anti_aliasing.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
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

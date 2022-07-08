/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:10 by sesim             #+#    #+#             */
/*   Updated: 2022/07/08 10:55:25 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int	main(int ac, char **av)
{
	t_point	**point;
	t_mlx	mlx;

	point = get_map(ac, av, &mlx.ucs);
	for (int i = 0; i < mlx.ucs.h; ++i)
	{
		for (int j = 0; j < mlx.ucs.w; ++j)
		{
			printf("%d %d %d %d\n", point[j][i].x, point[j][i].y, point[j][i].z, point[j][i].color);
		}
	}
}

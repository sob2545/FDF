/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:10 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 22:57:30 by sesim            ###   ########.fr       */
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
			printf("%d ", point[j][i].x);
			printf("%d ", point[j][i].y);
			printf("%d ", point[j][i].z);
			printf("%d ", point[j][i].color);
		}
	}
}

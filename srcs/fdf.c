/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:10 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 23:13:57 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>

void	set_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1280, 720, "FDF");
	ft_bzero(&mlx->handler, sizeof(t_handler));
}

int	main_loop(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img->ptr);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	fdf->mlx->img->ptr = mlx_new_image(fdf->mlx->mlx, 1600, 900);
	fdf->mlx->img->data = (int *)mlx_get_data_addr(fdf->mlx->img->ptr, \
		&(fdf->mlx->img->bpp), &(fdf->mlx->img->size_l), \
		&(fdf->mlx->img->endian));
	draw_liner(fdf);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_point	**point;
	t_mlx	mlx;

	point = get_map(ac, av, &mlx.ucs);
	fdf.point = point;
	set_mlx(&mlx);
	fdf.mlx = &mlx;
	fdf.mlx->img = ft_calloc(1, sizeof(t_img));
	fdf.mlx->img->ptr = mlx_new_image(mlx.mlx, 1280, 720);
	fdf.mlx->img->data = (int *)mlx_get_data_addr(mlx.img->ptr, \
		&(mlx.img->bpp), &(mlx.img->size_l), &(mlx.img->endian));
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, &fdf);
	mlx_loop_hook(mlx.mlx, main_loop, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
	/*
	for (int i = 0; i < mlx.ucs.h; ++i)
	{
		for (int j = 0; j < mlx.ucs.w; ++j)
			printf("%d %d %d %d\n", point[i][j].x, point[i][j].y,point[i][j].z, point[i][j].color);
	}
	*/
}

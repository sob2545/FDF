/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:06:54 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:26:30 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include "fdf.h"

void	set_mlx(t_mlx *mlx)
{
	int	scale;

	scale = 1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FdF");
	ft_bzero(&(mlx->handler), sizeof(t_handler));
	mlx->handler.pro_mod = 0;
	while (scale * mlx->ucs.w < WIN_W - 500 && scale * mlx->ucs.h < WIN_H - 500)
		scale++;
	mlx->handler.scale = scale;
	mlx->handler.first_scale = scale;
	mlx->handler.mv_x = WIN_W / 2;
	mlx->handler.mv_y = WIN_H / 2;
}

void	projection(t_point *point, t_handler handler)
{
	if (handler.pro_mod == 0)
		ft_isometric(&point->iso_x, &point->iso_y, point->ro_z);
	else
		parallel(point);
}

int	main_loop(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img->ptr);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	fdf->mlx->img->ptr = mlx_new_image(fdf->mlx->mlx, WIN_W, WIN_H);
	fdf->mlx->img->data = (int *)mlx_get_data_addr(fdf->mlx->img->ptr, \
		&(fdf->mlx->img->bpp), &(fdf->mlx->img->size_l), \
		&(fdf->mlx->img->endian));
	rotate(fdf);
	bresen_line_1(fdf);
	bresen_line_2(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, \
		fdf->mlx->img->ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	t_point	**point;

	fdf.mlx = ft_calloc(1, sizeof(t_mlx));
	point = get_map(ac, av, &(fdf.mlx->ucs));
	fdf.point = point;
	set_mlx(fdf.mlx);
	fdf.mlx->img = ft_calloc(1, sizeof(t_img));
	fdf.mlx->img->ptr = mlx_new_image(fdf.mlx->mlx, WIN_W, WIN_H);
	fdf.mlx->img->data = (int *)mlx_get_data_addr(fdf.mlx->img->ptr, \
		&(fdf.mlx->img->bpp), &(fdf.mlx->img->size_l), &(fdf.mlx->img->endian));
	mlx_hook(fdf.mlx->win, X_EVENT_KEY_PRESS, 0, key_press, &fdf.mlx);
	mlx_hook(fdf.mlx->win, X_EVENT_MOUSE_PRESS, 0, mouse_press, &fdf.mlx);
	mlx_hook(fdf.mlx->win, 17, 0, terminate, &fdf.mlx);
	mlx_loop_hook(fdf.mlx->mlx, main_loop, &fdf);
	mlx_loop(fdf.mlx->mlx);
	return (0);
}

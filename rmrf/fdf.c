#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h>
#include "fdf.h"
#include <stdio.h>

void	bresenham_x(double start_x, double start_y, double finish_x, double finish_y, t_fdf *fdf)
{
	double width;
	double height;
	double	x;
	double	y;
	double	formula;
	double Yfactor;

	width = finish_x - start_x;
	height = finish_y - start_y;
	Yfactor = 1;
	if (height < 0)
	{
		Yfactor = -1;
		height *= -1;
	}
	x = start_x;
	y = start_y;
	formula = 2 * height - width;
	while (x < finish_x)
	{
		if (formula < 0)
			formula += (2 * height);
		else
		{
			y += Yfactor;
			formula += 2 * (height - width);
		}
		if ((int)x + (int)fdf->mlx->handler.mv_x < 0 || (int)x + (int)fdf->mlx->handler.mv_x >= WIN_W \
			|| (WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x) < 0 \
			|| (WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x) > WIN_W * WIN_H)

		{
			x+= 1;
			continue ;
		}
		fdf->mlx->img->data[(WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x)] = 0xFFFFFF;
		x += 1;
	}
}

void	bresenham_y(double start_x, double start_y, double finish_x, double finish_y, t_fdf *fdf)
{
	double width;
	double height;
	double	x;
	double	y;
	double	formula;
	double Xfactor;
	width = finish_x - start_x;
	height = finish_y - start_y;
	Xfactor = 1;
	if (width < 0)
	{
		Xfactor = -1;
		width *= -1;
	}

	x = start_x;
	y = start_y;
	formula = 2 * width - height;
	while (y < finish_y)
	{
		if (formula < 0)
			formula += (2 * width);
		else
		{
			x += Xfactor;
			formula += 2 * (width - height);
		}
		if ((int)x + (int)fdf->mlx->handler.mv_x < 0 || (int)x + (int)fdf->mlx->handler.mv_x >= WIN_W \
			|| (int)(y + fdf->mlx->handler.mv_y) > WIN_H || \
			(WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x) < 0 \
			|| (WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x) > WIN_W * WIN_H)
		{
			y += 1;
			continue;
		}
		fdf->mlx->img->data[(WIN_W * (int)(y + fdf->mlx->handler.mv_y) + (int)x + (int)fdf->mlx->handler.mv_x)] = 0x00FF00;
		y += 1;
	}
}

void	bresenham(double start_x, double start_y, double finish_x, double finish_y, t_fdf *fdf)
{
	double width;
	double height;

	width = (finish_x - start_x);
	if (width < 0)
		width *= -1;
	height = (finish_y - start_y);
	if (height < 0)
		height *= -1;
	if (width > height)
	{
		if (start_x > finish_x)
			bresenham_x(finish_x, finish_y, start_x, start_y, fdf);
		else
			bresenham_x(start_x, start_y, finish_x, finish_y, fdf);
	}
	else
	{
		if (start_y > finish_y)
			bresenham_y(finish_x, finish_y, start_x, start_y, fdf);
		else
			bresenham_y(start_x, start_y, finish_x, finish_y, fdf);
	}
}

int	terminate(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->mlx->ucs.h)
	{
		free(fdf->point[i]);
		i++;
	}
	free(fdf->point);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img);
	mlx_destroy_window(fdf->mlx->mlx, fdf->mlx->win);
	exit (0);
}

void	angle_init(t_handler *handler, int flag)
{
	if (flag == 0)
	{
		handler->angle_x = 0;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	else if (flag == 1)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 0;
	}
	else if (flag == 2)
	{
		handler->angle_x = -90;
		handler->angle_y = 0;
		handler->angle_z = 90;
	}
}

void	set_projection(int key, t_fdf *fdf)
{
	if (key == KEY_R)
	{
		angle_init(&(fdf->mlx->handler), 0);
		if (fdf->mlx->handler.pro_mod == 0)
			++(fdf->mlx->handler.pro_mod);
		else
			fdf->mlx->handler.pro_mod = 0;
	}
	else if (key == KEY_1 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 0);
	else if (key == KEY_2 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 1);
	else if (key == KEY_3 && fdf->mlx->handler.pro_mod != 0)
		angle_init(&(fdf->mlx->handler), 2);
}

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		terminate(fdf);
	else if (keycode == KEY_UP)
		(fdf->mlx->handler.mv_y) -= 30;
	else if (keycode == KEY_DOWN)
		(fdf->mlx->handler.mv_y) += 30;
	else if (keycode == KEY_LEFT)
		(fdf->mlx->handler.mv_x) -= 30;
	else if (keycode == KEY_RIGHT)
		(fdf->mlx->handler.mv_x) += 30;
	else if (keycode == KEY_ZM_U)
		(fdf->mlx->handler.scale) += fdf->mlx->handler.scale * 0.1;
	else if (keycode == KEY_ZM_D)
		(fdf->mlx->handler.scale) -= fdf->mlx->handler.scale * 0.1;
	else if (keycode == KEY_W)
		++(fdf->mlx->handler.angle_x);
	else if (keycode == KEY_S)
		--(fdf->mlx->handler.angle_x);
	else if (keycode == KEY_A)
		++(fdf->mlx->handler.angle_y);
	else if (keycode == KEY_Q)
		--(fdf->mlx->handler.angle_y);
	else if (keycode == KEY_E)
		++(fdf->mlx->handler.angle_z);
	else if (keycode == KEY_D)
		--(fdf->mlx->handler.angle_z);
	set_projection(keycode, fdf);
	return (0);
}

void	set_mlx(t_mlx *mlx)
{
	int	scale;

	scale = 1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FdF");
	ft_bzero(&(mlx->handler), sizeof(t_handler));
	mlx->handler.pro_mod = 0;
	mlx->handler.line_mod = 0;
	while (scale * mlx->ucs.w  < WIN_W- 500 && scale * mlx->ucs.h < WIN_H - 500)
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
	t_img	*img;
	double	x;
	double	y;

	img = fdf->mlx->img;
	mlx_destroy_image(fdf->mlx->mlx, fdf->mlx->img->ptr);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	fdf->mlx->img->ptr = mlx_new_image(fdf->mlx->mlx, WIN_W, WIN_H);
	fdf->mlx->img->data = (int *)mlx_get_data_addr(fdf->mlx->img->ptr, \
		&(fdf->mlx->img->bpp), &(fdf->mlx->img->size_l), &(fdf->mlx->img->endian));
	for (int i = 0; i < fdf->mlx->ucs.h; ++i)
	{
		for (int j = 0; j < fdf->mlx->ucs.w; ++j)
		{
			x = j - fdf->mlx->ucs.w / 2;
			y = i - fdf->mlx->ucs.h / 2;
			rotate_z(x, y, &(fdf->point[i][j]), fdf->mlx->handler.angle_z);
			rotate_y(fdf->point[i][j].iso_x, fdf->point[i][j].z, &fdf->point[i][j], fdf->mlx->handler.angle_y);
			rotate_x(fdf->point[i][j].iso_y, fdf->point[i][j].ro_z, &fdf->point[i][j], fdf->mlx->handler.angle_x);
			projection(&fdf->point[i][j], fdf->mlx->handler);
		}
	}
	for (int i = 0; i < fdf->mlx->ucs.h; ++i)
	{
		for (int j = 1; j < fdf->mlx->ucs.w; ++j)
		{
			bresenham(fdf->mlx->handler.scale * fdf->point[i][j - 1].iso_x, fdf->mlx->handler.scale * fdf->point[i][j - 1].iso_y, fdf->mlx->handler.scale * fdf->point[i][j].iso_x, fdf->mlx->handler.scale * fdf->point[i][j].iso_y, fdf);
		}
	}
	for (int i = 1; i < fdf->mlx->ucs.h; ++i)
	{
		for (int j = 0; j < fdf->mlx->ucs.w; ++j)
		{
			bresenham(fdf->mlx->handler.scale * fdf->point[i - 1][j].iso_x, fdf->mlx->handler.scale * fdf->point[i - 1][j].iso_y, fdf->mlx->handler.scale * fdf->point[i][j].iso_x, fdf->mlx->handler.scale * fdf->point[i][j].iso_y, fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->mlx->img->ptr, 0, 0);
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
	mlx_hook(fdf.mlx->win, 17, 0, terminate, &fdf.mlx);
	printf("%d, %d\n", fdf.mlx->ucs.h, fdf.mlx->ucs.w);
	mlx_loop_hook(fdf.mlx->mlx, main_loop, &fdf);
	mlx_loop(fdf.mlx->mlx);
	return (0);
}

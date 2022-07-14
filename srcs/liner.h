/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/14 14:14:42 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINER_H
# define LINER_H

# include "fdf.h"

typedef struct s_delta_val
{
	double	dx;
	double	dy;
}	t_delta_val;

typedef struct s_rgb
{
	int	color;
	int	a;
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_vertex
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	gradient;
	t_rgb	rgb1;
	t_rgb	rgb2;
}	t_vertex;

typedef struct s_bresen_val
{
	int		color;
	double	line_w;
	double	line_h;
	double	x;
	double	y;
	double	init_val;
	double	factor;
}	t_bresen_val;

/* liner utils */
void	double_swap(double *x, double *y);
void	color_swap(int *x, int *y);

/* color func */
int		set_grad_color(t_vertex *line, double grad);
void	set_color(t_vertex *line);

/* bresenham func */
void	bresenham(t_mlx mlx, t_vertex line);
void	bresenham_x(t_mlx mlx, t_vertex line);
void	bresenham_y(t_mlx mlx, t_vertex line);
void	draw_x(t_mlx mlx, t_vertex line, t_bresen_val *val);
void	draw_y(t_mlx mlx, t_vertex line, t_bresen_val *val);

/* anti aliasing utils */
int		dtoi(double val);
int		ft_round(double val);
double	dec_point(double val);
double	rev_dec_point(double val);
int		check_win(double x, double y, double mv_x, double mv_y);

/* anti aliasing func */
void	first_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	first_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	last_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	last_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	middle_pixel_1(t_mlx mlx, t_vertex line, t_vertex pxvertex);
void	middle_pixel_2(t_mlx mlx, t_vertex line, t_vertex pxvertex);
int		set_grad(t_rgb color, double grad);
void	anti_alias(t_mlx mlx, t_vertex line);

/* euler rotation func */
void	euler_rotate(t_fdf *fdf, int h, int w);
void	rotate_x(double y, double z, t_point *point, double angle);
void	rotate_y(double y, double z, t_point *point, double angle);
void	rotate_z(double y, double z, t_point *point, double angle);

/* side coordinate euler rotation func */
void	rotate_cs_x(double y, double z, t_point *point, double angle);
void	rotate_cs_y(double y, double z, t_point *point, double angle);
void	rotate_cs_z(double y, double z, t_point *point, double angle);

/* projection func */
void	ft_isometric(double *x, double *y, double z);
void	ft_parallel(t_point *point, int mod);

#endif

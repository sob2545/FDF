/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 09:49:14 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINER_H
# define LINER_H

# include "fdf.h"

typedef struct s_quater
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quater;

typedef struct s_quater_param
{
	double	x_pow;
	double	y_pow;
	double	z_pow;
	double	w_x;
	double	w_y;
	double	w_z;
	double	x_y;
	double	x_z;
	double	y_z;
}	t_quater_param;

void	ft_swap(int *x, int *y);
int		dtoi(double val);
int		ft_round(double val);
double	dec_point(double val);
double	rev_dec_point(double val);
void	first_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	first_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	last_pixel_1(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	last_pixel_2(t_mlx mlx, t_vertex line, t_vertex *pxvertex);
void	middle_pixel_1(t_mlx mlx, t_vertex line, t_vertex pxvertex);
void	middle_pixel_2(t_mlx mlx, t_vertex line, t_vertex pxvertex);
int		get_color(int color, double grad, double gap);
void	anti_alias(t_mlx mlx, t_vertex line);

void	rotate_x(double y, double z, t_point *point, double angle);
void	rotate_y(double y, double z, t_point *point, double angle);
void	rotate_z(double y, double z, t_point *point, double angle);

#endif

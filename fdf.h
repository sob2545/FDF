/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/04 10:13:35 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_ucs
{
	double	scale;
	double	w;
	double	h;
	double	angle;
	int		color;
}	t_ucs;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	t_ucs	ucs;
}	t_mlx;

typedef struct	s_point
{
	double	iso_x;
	double	iso_y;
	double	z;
}	t_point;

typedef struct	s_ptr
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	double	gradient;
}	t_ptr;

void	ft_swap(int *x, int *y);
int		dtoi(double val);
int		ft_round(double val);
double	dec_point(double val);
double	rev_dec_point(double val);
void	first_pixel_1(t_mlx mlx, t_ptr line, t_ptr *pxl_point);
void	first_pixel_2(t_mlx mlx, t_ptr line, t_ptr *pxl_point);
void	last_pixel_1(t_mlx mlx, t_ptr line, t_ptr *pxl_point);
void	last_pixel_2(t_mlx mlx, t_ptr line, t_ptr *pxl_point);
void	middle_pixel(t_mlx mlx, t_ptr line, t_ptr pxl_point, int flag);
int		get_color(t_mlx mlx, double grad, double gap);
void	anti_alias(t_mlx mlx, t_ptr line);

#endif

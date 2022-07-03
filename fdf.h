/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/03 17:21:44 by sesim            ###   ########.fr       */
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

#endif

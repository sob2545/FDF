/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/10 22:56:22 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTI_ALIASING_H
# define ANTI_ALIASING_H

# include "fdf.h"

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

#endif

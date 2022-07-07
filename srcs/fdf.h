/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 22:53:46 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEX "0123456789abcdef"

typedef struct s_ucs
{
	double	scale;
	double	w;
	double	h;
	double	angle;
	int		color;
}	t_ucs;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	t_ucs	ucs;
}	t_mlx;

typedef struct s_delta_val
{
	double	dx;
	double	dy;
}	t_delta_val;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	double	iso_x;
	double	iso_y;
	double	ro_z;
}	t_point;

typedef struct s_quater
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quater;

typedef struct s_vertex
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	gradient;
}	t_vertex;

t_point	**get_map(int ac, char **map, t_ucs *ucs);
void	ft_error(char *error_no);
void	free_file(char *file, int flag);
t_point	**free_file_point(char *file, t_point **point);
void	check_file_name(char *file);




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
int		get_color(t_mlx mlx, double grad, double gap);
void	anti_alias(t_mlx mlx, t_vertex line);

#endif

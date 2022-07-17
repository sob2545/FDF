/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:29:18 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:25:52 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEX "0123456789abcdef"

/*   EVENT NUMBER   */
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_MOUSE_PRESS 4

/*      KEYCODE     */
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_Z 6
# define KEY_F 3
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20

/*    MOUSE CODE      */
# define KEY_ZM_U 30
# define KEY_ZM_D 33

/*     WINDOW SIZE     */
# define WIN_W 1280
# define WIN_H 720

typedef struct s_ucs
{
	int	w;
	int	h;
}	t_ucs;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_handler
{
	double	scale;
	double	first_scale;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int		mv_x;
	int		mv_y;
	int		pro_mod;
	int		view_point;
}	t_handler;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_ucs		ucs;
	t_img		*img;
	t_handler	handler;
}	t_mlx;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	double	ro_z;
	double	iso_x;
	double	iso_y;
}	t_point;

typedef struct s_fdf
{
	t_mlx	*mlx;
	t_point	**point;
}	t_fdf;

typedef struct s_vertex
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	gradient;
	int		color1;
	int		color2;
}	t_vertex;

typedef struct s_delta_val
{
	double	dx;
	double	dy;
}	t_delta_val;

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

/* map parser */
t_point	**get_map(int ac, char **map, t_ucs *ucs);
t_point	**free_file_point(char *file, t_point **point, t_ucs *ucs);
void	ft_error(char *error_no);
void	free_file(char *file, int flag);
void	check_file_name(char *file);
int		is_set(char *set, int c);
int		point_init(char *map, t_point **point, int w, int h);
int		get_map_data(int w_cnt, char *map, t_ucs *ucs);
int		check_ucs(int *height, char *map, t_point **point, t_ucs *ucs);

/*   euler angle   */
void	rotate_x(double y, double z, t_point *point, double angle);
void	rotate_y(double x, double z, t_point *point, double angle);
void	rotate_z(double x, double y, t_point *point, double angle);

/*   line functions    */
int		check_win_size(double x, double y, double mv_x, double mv_y);
void	double_swap(double *x, double *y);
void	color_swap(int *x, int *y);
void	rotate(t_fdf *fdf);
void	bresen_line_1(t_fdf *fdf);
void	bresen_line_2(t_fdf *fdf);
void	bresenham(t_vertex line, t_fdf *fdf);
void	bresenham_x(t_vertex line, t_fdf *fdf);
void	bresenham_y(t_vertex line, t_fdf *fdf);

/*   projection   */
void	projection(t_point *point, t_handler handler);
void	ft_isometric(double *x, double *y, double z);
void	parallel(t_point *point);

/*    key functions   */
int		key_press(int keycode, t_fdf *fdf);
int		terminate(t_fdf *fdf);
int		mouse_press(int button, int x, int y, t_fdf *fdf);
void	obj_init(int keycode, t_fdf *fdf);
void	obj_rotate(int keycode, t_fdf *fdf);
void	obj_move(int keycode, t_fdf *fdf);

#endif

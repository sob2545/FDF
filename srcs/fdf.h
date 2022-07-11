/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:30:22 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 23:12:50 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X_EVENT_KEY_PRESS 2
# define HEX "0123456789abcdef"
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define WIN_W 1280
# define WIN_H 720

typedef struct s_ucs
{
	int		w;
	int		h;
}	t_ucs;

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
	int		ro_mod;
	int		line_mod;
	int		help;
}	t_handler;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

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

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_ucs		ucs;
	t_img		*img;
	t_handler	handler;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx	*mlx;
	t_point	**point;
}	t_fdf;

/* map parser */
t_point	**get_map(int ac, char **map, t_ucs *ucs);
void	ft_error(char *error_no);
void	free_file(char *file, int flag);
t_point	**free_file_point(char *file, t_point **point, t_ucs *ucs);
void	check_file_name(char *file);
int		is_set(char *set, int c);
int		point_init(char *map, t_point **point, int w, int h);
int		get_map_data(int w_cnt, char *map, t_ucs *ucs);
int		check_ucs(int *height, char *map, t_point **point, t_ucs *ucs);

/* draw line func */
void	draw_liner(t_fdf *fdf);

/* mlx loop func */
int		key_press(int keycode, t_fdf *fdf);

#endif

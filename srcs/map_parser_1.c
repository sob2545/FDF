/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 23:03:10 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

int	map_checker_1(char *map, t_ucs *ucs)
{
	int	w_cnt;

	while (*map)
	{
		w_cnt = 0;
		if (ft_strchr(" \t", *map))
			map++;
		else if (*map == '\n')
		{
			++(ucs->h);
			map++;
		}
		else
		{
			if (ucs->h == 0)
				(ucs->w)++;
			w_cnt++;
			while (*map && (*map != ' ' || *map != '\t'))
			{
				if (ft_isalpha(*map))
					ft_tolower(*map);
				map++;
			}
		}
		if (ucs->w != w_cnt)
			return (0);
	}
	return (1);
}

int	point_init(char *map, t_point **point, int w, int h)
{
	int	i;

	i = 0;
	if (ft_isdigit(*map))
	{
		point[h][w].x = w;
		point[h][w].y = h;
		point[h][w].z = ft_adtoi(map);
		while (ft_isdigit(map[i]))
			i++;
		if (map[i] == ',')
		{
			++i;
			point[h][w].color = ft_atoui_base(map + i, HEX);
			while (ft_strchr(HEX, map[i]) != 0)
				i++;
		}
		else if ((map[i] != ',') && (map[i] != ' ') && (map[i] != '\t'))
			return (-1);
		else
			++i;
	}
	return (i);
}

int	map_checker_2(char *map, t_point **point, t_ucs *ucs)
{
	int	i;
	int	width;
	int	height;

	height = 0;
	while (height < ucs->h)
	{
		width = 0;
		while (*map != '\n')
		{
			if (ft_strchr(" \t", *map) != 0)
				map++;
			else
				i = point_init(map, point, width, height);
			if (i < 0)
				return (0);
			map += i;
		}
		map++;
		height++;
	}
	return (1);
}

char	*read_map(int ac, char **file)
{
	char	*map;
	int		fd;

	if (ac != 2)
		ft_error("Wrong Arguments!");
	check_file_name(file[1]);
	fd = open(file[1], O_RDONLY);
	if (fd < 0)
		ft_error("Read Fail!");
	map = get_file(fd);
	close (fd);
	if (map == 0)
		ft_error("Map Allocating Fail!");
	return (map);
}

t_point	**get_map(int ac, char **file, t_ucs *ucs)
{
	t_point	**point;
	char	*map;
	int		i;

	map = read_map(ac, file);
	if (map_checker_1(map, ucs) == 0)
		free_file(map, 1);
	point = ft_calloc(ucs->h, sizeof(t_point *));
	if (point == 0)
		free_file_point(map, point);
	i = -1;
	while (++i < ucs->h)
	{
		point[i] = ft_calloc(ucs->w, sizeof(t_point));
		if (point[i] == 0)
			free_file_point(map, point);
	}
	if (map_checker_2(map, point, ucs) == 0)
	{
		free_file_point(map, point);
		ft_error("Map Allocating Fail!");
	}
	free_file(map, 2);
	return (point);
}

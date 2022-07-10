/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/10 00:37:06 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static int	is_set(char *set, int c)
{
	int	cmp;

	cmp = ft_tolower(c);
	while (*set)
	{
		if (*set == cmp)
			return (1);
		set++;
	}
	return (-1);
}

int	map_checker_1(char *map, t_ucs *ucs)
{
	int	w_cnt;
	int	i;

	i = 0;
	ucs->w = 0;
	ucs->h = 0;
	w_cnt = 0;
	while (map[i] != '\0')
	{
		if (is_set(" \t", map[i]) == 1)
			i++;
		else if (map[i] == '\n')
		{
			if ((ucs->w != w_cnt) || ucs->w == 0)
				return (0);
			w_cnt = 0;
			ucs->h += 1;
			i++;
		}
		else
		{
			if (ucs->h == 0)
				ucs->w += 1;
			w_cnt++;
			while (map[i] && (is_set(" \t\n", map[i]) == -1))
				i++;
		}
	}
	return (1);
}

int	point_init(char *map, t_point **point, int w, int h)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (ft_isdigit(*map) || *map == '-')
	{
		point[h][w].x = w;
		point[h][w].y = h;
		point[h][w].z = ft_atoi(map);
		if (*map == '-')
			i++;
		while (ft_isdigit(map[i]))
			i++;
		if (map[i] == ',')
		{
			++i;
			point[h][w].color = ft_atoi_hex(map + i);
			if (point[h][w].color != -1)
				i += 2;
			while (is_set(HEX, map[i]) == 1)
			{
				cnt ++;
				i++;
			}
			if (cnt > 7)
				return (-1);
			if (map[i] != '\0' && map[i] != ' ' && map[i] != '\t')
				return (-1);
		}
		else if (ft_isspace(map[i]) || map[i] == '\0')
			point[h][w].color = 0xFFFFFF;
		else
			return (-1);
	}
	printf("%d %d %d %d\n", point[h][w].x, point[h][w].y, point[h][w].z, point[h][w].color);
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
		i = 0;
		width = 0;
		while (*map != '\n')
		{
			if (is_set(" \t", *map) != -1)
				map++;
			else
			{
				i = point_init(map, point, width, height);
				if (i < 0)
					return (0);
				width++;
				map += i;
			}
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
	printf("%s\n", map);
	if (map_checker_1(map, ucs) == 0)
	{
		printf("f");
		free_file(map, 1);
	}
	printf("%d, %d\n", ucs->w, ucs->h);
	point = ft_calloc(ucs->h, sizeof(t_point *));
	if (point == 0)
		ft_error("Allocating Fail");
	i = -1;
	while (++i < ucs->h)
	{
		point[i] = ft_calloc(ucs->w, sizeof(t_point));
		if (point[i] == 0)
			free_file_point(map, point, ucs);
	}
	if (map_checker_2(map, point, ucs) == 0)
	{
		printf("chek");
		free_file_point(map, point, ucs);
		ft_error("Map Allocating has Fail!");
	}
	free_file(map, 2);
	return (point);
}

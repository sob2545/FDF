/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/08 11:00:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static int	is_set(char *set, int c)
{
	while (*set)
	{
		if (*set == c)
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
		if (is_set(" \t\n", map[i]) == 1)
		{
			if (map[i] == '\n')
			{
				w_cnt = 0;
				ucs->h += 1;
			}
			printf("a");
			i++;
		}
		else
		{
			if (ucs->h == 0)
				ucs->w += 1;
			w_cnt++;
			while (map[i] && (is_set(" \t\n", map[i]) == -1))
			{
				if (ft_isalpha(map[i]))
					ft_tolower(map[i]);
				i++;
				printf("c");
			}
			printf("b");
		}
		printf("%d %d %d\n", ucs->w, ucs->h, w_cnt);
		/*if (ucs->w != w_cnt)
		{
			printf("%d %d %d\n", ucs->w, ucs->h, w_cnt);
			return (0);
		}*/
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
			point[h][w].color = ft_atoi_hex(map + i);
			i += 9;
			if (map[i] != '\0' || !(ft_isspace(map[i])))
				return (-1);
		}
		else if (map[i] == ' ' || map[i] == '\t' || map[i] == '\0')
			point[h][w].color = 0xFFFFFF;
		else
			return (-1);
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
		i = 0;
		width = 0;
		while (*map != '\n')
		{
			if (is_set(" \t", *map) != -1)
				map++;
			else
				i = point_init(map, point, width, height);
			if (i < 0)
				return (0);
			width++;
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
	printf("%s\n", map);
	if (map_checker_1(map, ucs) == 0)
	{
		printf("f");
		free_file(map, 1);
	}
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
		ft_error("Map Allocating Fail!");
	}
	free_file(map, 2);
	return (point);
}

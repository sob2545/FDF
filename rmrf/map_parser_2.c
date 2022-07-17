/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:23:43 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

int	is_set(char *set, int c)
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

int	get_map_data(int w_cnt, char *map, t_ucs *ucs)
{
	while (*map != '\0')
	{
		if (is_set(" \t", *map) == 1)
			map++;
		else if (*map == '\n')
		{
			if ((ucs->w != w_cnt) || ucs->w == 0)
				return (-1);
			w_cnt = 0;
			ucs->h += 1;
			map++;
		}
		else
		{
			if (ucs->h == 0)
				ucs->w += 1;
			w_cnt++;
			while (*map && (is_set(" \t\n", *map) == -1))
				map++;
		}
	}
	return (1);
}

int	check_color(char *map)
{
	int	i;

	i = 0;
	while (is_set(HEX, map[i]) == 1)
		i++;
	if (i >= 7)
		return (-1);
	if (map[i] != '\0' && map[i] != ' ' && map[i] != '\t' && map[i] != '\n')
		return (-1);
	return (i);
}

int	init_color(char *map, t_point **point, int w, int h)
{
	int	i;
	int	cnt;

	i = 0;
	if (*map == '-')
		i++;
	while (ft_isdigit(map[i]))
		i++;
	if (map[i] == ',')
	{
		++i;
		point[h][w].color = ft_atoi_hex(map + i);
		if (point[h][w].color == -1)
			return (-1);
		i += 2;
		cnt = check_color(map + i);
		if (cnt == -1)
			return (-1);
		i += cnt;
	}
	else if (ft_isspace(map[i]) || map[i] == '\0')
		point[h][w].color = 0xFFFFFF;
	else
		return (-1);
	return (i);
}

int	point_init(char *map, t_point **point, int w, int h)
{
	int	i;

	i = 0;
	if (ft_isdigit(*map) || *map == '-')
	{
		point[h][w].x = w;
		point[h][w].y = h;
		point[h][w].z = ft_atoi(map);
		i = init_color(map, point, w, h);
		if (i == -1)
			return (-1);
	}
	return (i);
}

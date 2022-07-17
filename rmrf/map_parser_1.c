/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:45:02 by sesim             #+#    #+#             */
/*   Updated: 2022/07/18 08:00:58 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

int	map_checker_1(char *map, t_ucs *ucs)
{
	int	w_cnt;

	w_cnt = 0;
	ucs->w = 0;
	ucs->h = 0;
	if (get_map_data(w_cnt, map, ucs) == -1)
		return (0);
	return (1);
}

int	map_checker_2(char *map, t_point **point, t_ucs *ucs)
{
	int	height;

	height = 0;
	if (check_ucs(&height, map, point, ucs) != 1)
		return (0);
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
		free_file_point(map, point, ucs);
		ft_error("Map Allocating has Fail!");
	}
	free_file(map, 2);
	return (point);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:03:47 by sesim             #+#    #+#             */
/*   Updated: 2022/07/11 08:09:06 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

void	ft_error(char *error_no)
{
	ft_putendl_fd(error_no, 2);
	exit(1);
}

t_point	**free_file_point(char *file, t_point **point, t_ucs *ucs)
{
	int	i;

	i = 0;
	free (file);
	file = 0;
	while (i < ucs->h)
	{
		free (point[i]);
		i++;
	}
	free (point);
	return (0);
}

void	free_file(char *file, int flag)
{
	free (file);
	file = 0;
	if (flag == 1)
		ft_error("Wrong Map!");
}

void	check_file_name(char *file)
{
	size_t	map_len;

	map_len = ft_strlen(file);
	if (map_len < 5)
		ft_error("Where is map's name?");
	if (ft_strncmp((file + map_len - 4), ".fdf\0", 5) != 0)
		ft_error("Did you confused with other project?!");
}

int	check_ucs(int *height, char *map, t_point **point, t_ucs *ucs)
{
	int	i;
	int	width;

	while (*height < ucs->h)
	{
		i = 0;
		width = 0;
		while (*map != '\n')
		{
			if (is_set(" \t", *map) != -1)
				map++;
			else
			{
				i = point_init(map, point, width, *height);
				if (i < 0)
					return (0);
				width++;
				map += i;
			}
		}
		map++;
		*height += 1;
	}
	return (1);
}

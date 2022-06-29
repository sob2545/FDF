/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:53:34 by sesim             #+#    #+#             */
/*   Updated: 2022/06/01 22:55:39 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *bac)
{
	char	*buf;
	ssize_t	r_cnt;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == 0)
		return (0);
	r_cnt = 1;
	while (!ft_strchr(bac, '\n') && r_cnt != 0)
	{
		r_cnt = read(fd, buf, BUFFER_SIZE);
		if (r_cnt == -1)
			break ;
		buf[r_cnt] = '\0';
		bac = ft_strjoin(bac, buf);
	}
	free(buf);
	buf = 0;
	return (bac);
}

char	*get_line(char *bac)
{
	char	*line;
	int		len;

	if (bac[0] == 0)
		return (0);
	if (ft_strchr(bac, '\n'))
		len = ft_strchr(bac, '\n') - bac + 2;
	else
		len = ft_strlen(bac) + 1;
	line = malloc(sizeof(char) * len);
	if (line == 0)
		return (0);
	ft_strlcpy(line, bac, len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bac;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bac = reader(fd, bac);
	if (bac == 0)
		return (0);
	res = get_line(bac);
	bac = new_line(bac);
	return (res);
}

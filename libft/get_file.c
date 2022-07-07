/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:53:34 by sesim             #+#    #+#             */
/*   Updated: 2022/07/07 22:12:12 by sesim            ###   ########.fr       */
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
	while (!ft_strchr_g(bac, '\0') && r_cnt != 0)
	{
		r_cnt = read(fd, buf, BUFFER_SIZE);
		if (r_cnt == -1)
			break ;
		buf[r_cnt] = '\0';
		bac = ft_strjoin_g(bac, buf);
	}
	free(buf);
	buf = 0;
	return (bac);
}

char	*get_file(int fd)
{
	static char	*bac;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bac = reader(fd, bac);
	if (bac == 0)
		return (0);
	return (bac);
}

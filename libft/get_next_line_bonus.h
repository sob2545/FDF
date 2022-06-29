/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:39:01 by sesim             #+#    #+#             */
/*   Updated: 2022/06/16 11:51:38 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	char			*line;
	int				idx;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*new_line(char *bac);
char	*read_line(int fd, char *bac);
char	*get_line(char *bac);
char	*get_next_line(int fd);
char	*lst_new(t_list *head, int fd);

#endif

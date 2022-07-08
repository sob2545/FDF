/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:29:10 by sesim             #+#    #+#             */
/*   Updated: 2022/07/08 10:45:11 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_isspace(int c);
int		ft_tolower(int c);

static int	base_cmp(char c, char *str)
{
	int	i;

	i = 0;
	ft_tolower(c);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_hex(char *str)
{
	char	*base = "0123456789abcdef";
	int	k;
	int	base_num;
	int	dec_num;

	k = 0;
	dec_num = 0;
	while (ft_isspace(str[k]))
		k++;
	if (str[k] == '0' && str[k + 1] == 'x')
		k += 3;
	else
		return (-1);
	base_num = base_cmp(str[k], base);
	while (base_num != -1)
	{
		dec_num = (dec_num * ft_strlen(base)) + base_num;
		k++;
		base_num = base_cmp(str[k], base);
	}
	return (dec_num);
}

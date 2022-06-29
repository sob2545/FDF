/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:29:10 by sesim             #+#    #+#             */
/*   Updated: 2022/06/29 12:02:30 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
size_t	ft_isspace(char str, int ptr);

int	ft_base_cmp(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	invalid_case(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == 43 || str[i] == 45)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	k;
	int	pn;
	int	base_num;
	int	dec_num;

	k = 0;
	dec_num = 0;
	if (invalid_case(base) == 1)
	{
		pn = ft_isspace(str, &k);
		base_num = ft_strchr(base, str[k]) - str;
		while (base_num != -1)
		{
			dec_num = (dec_num * ft_strlen(base)) + base_num;
			k++;
			base_num = ft_base_cmp(str[k], base);
		}
		return (pn * dec_num);
	}
	return (0);
}

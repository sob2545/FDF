/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:29:10 by sesim             #+#    #+#             */
/*   Updated: 2022/07/08 08:10:24 by sesim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_isspace(int c);

static int	base_cmp(char c, char *str)
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
		return (-1);
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (-1);
			j++;
		}
		if (str[i] == 43 || str[i] == 45)
			return (-1);
		i++;
	}
	return (1);
}

unsigned int	ft_atoui_base(char *str, char *base)
{
	int	k;
	int	base_num;
	int	dec_num;

	k = 0;
	dec_num = 0;
	if (invalid_case(base) == 1)
	{
		while (ft_isspace(str[k]))
			k++;
		base_num = base_cmp(str[k], base);
		while (base_num != -1)
		{
			dec_num = (dec_num * ft_strlen(base)) + base_num;
			k++;
			base_num = base_cmp(str[k], base);
		}
		return (dec_num);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <rhakh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 21:10:16 by rhakh             #+#    #+#             */
/*   Updated: 2016/12/27 21:11:08 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_fillit(t_ficord **cords, int i, char **res, int res_len)
{
	t_cord			pos;

	if (cords[i] == NULL)
		return (1);
	pos.x = 0;
	pos.y = 0;
	while (pos.x < res_len && pos.y < res_len)
	{
		if (ft_check_insert(cords[i], pos, res, res_len))
		{
			ft_do_insert(cords[i], pos, res);
			if (ft_fillit(cords, i + 1, res, res_len))
				return (1);
			ft_erase_figure(cords[i], pos, res);
		}
		pos.y = (pos.x == res_len - 1) ? pos.y + 1 : pos.y;
		pos.x = (pos.x == res_len - 1) ? 0 : pos.x + 1;
	}
	return (0);
}

int					ft_norm_sqrt(int len)
{
	int i;

	i = 1;
	while (i * i < len)
		i++;
	return (i);
}

char				**ft_get_field(int len)
{
	unsigned char	i;
	unsigned char	j;
	char			**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * len);
	while (i < len)
	{
		res[i] = (char *)malloc(sizeof(char) * len);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			res[i][j] = '.';
			j++;
		}
		i++;
	}
	return (res);
}

void				ft_get_result(t_ficord **cords, int len)
{
	char			**res;
	unsigned char	res_len;

	res_len = ft_norm_sqrt(len * 4);
	while (res_len < 26)
	{
		res = ft_get_field(res_len);
		if (ft_fillit(cords, 0, res, res_len))
			break ;
		res_len++;
	}
	ft_print_res(res, res_len);
}

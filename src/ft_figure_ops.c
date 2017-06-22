/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 20:52:17 by rhakh             #+#    #+#             */
/*   Updated: 2016/12/27 20:52:18 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_insert(t_ficord *cord,
				t_cord pos, char **res, int res_len)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (pos.y + cord->d[i].y >= res_len || pos.x + cord->d[i].x >= res_len)
			return (0);
		if (res[pos.y + cord->d[i].y][pos.x + cord->d[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void			ft_do_insert(t_ficord *cord, t_cord pos, char **res)
{
	int			j;

	j = 0;
	while (j < 4)
	{
		res[pos.y + cord->d[j].y][pos.x + cord->d[j].x] = cord->lett;
		j++;
	}
}

void			ft_erase_figure(t_ficord *cord, t_cord pos, char **res)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		res[pos.y + cord->d[i].y][pos.x + cord->d[i].x] = '.';
		i++;
	}
}

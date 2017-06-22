/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 20:51:26 by rhakh             #+#    #+#             */
/*   Updated: 2016/12/27 20:51:27 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void						ft_set_cords(char **figure, t_ficord *cord)
{
	unsigned char			i;
	unsigned char			j;
	unsigned char			k;
	t_cord					fst_cord;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (k == 0 && figure[i][j] == '#')
			{
				fst_cord.x = j;
				fst_cord.y = i;
			}
			if (figure[i][j] == '#')
			{
				cord->d[k].x = j - fst_cord.x;
				cord->d[k++].y = i - fst_cord.y;
			}
		}
	}
}

t_ficord					*ft_get_cords(char **figure)
{
	t_ficord				*cord;

	if ((cord = (t_ficord *)malloc(sizeof(t_ficord) * 1)) == NULL)
		return (NULL);
	ft_set_cords(figure, cord);
	return (cord);
}

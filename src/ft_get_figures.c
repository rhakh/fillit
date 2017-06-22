/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbondar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:58:13 by sbondar           #+#    #+#             */
/*   Updated: 2016/12/04 12:58:15 by sbondar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_get_figure(char *buf)
{
	char	**figure;

	figure = NULL;
	if (ft_figure_check(buf))
	{
		if ((figure = ft_strsplit(buf, '\n')) == NULL)
			return (NULL);
	}
	else
		return (NULL);
	return (figure);
}

int			ft_read_figure(int fd, char ***figures, t_ficord **cords, int i)
{
	char	buf[20];
	int		b;

	b = read(fd, buf, 20);
	if (b != 20)
		return (0);
	if (b == 0)
	{
		*figures = NULL;
		*cords = NULL;
		return (1);
	}
	if ((*figures = ft_get_figure(buf)) == NULL || i >= 26)
		return (0);
	(*cords) = ft_get_cords(*figures);
	(*cords)->lett = 'A' + i;
	return (2);
}

int			ft_read_n(int fd, char ***figures, t_ficord **cords)
{
	char	buf[20];
	int		b;

	b = read(fd, buf, 1);
	if (b == 0)
	{
		*(figures + 1) = NULL;
		*(cords + 1) = NULL;
		return (1);
	}
	else if (buf[0] != '\n')
		return (0);
	return (2);
}

char		***ft_get_figures(int fd, t_ficord **cords)
{
	int		i;
	int		ret;
	char	***figures;

	i = 0;
	if ((figures = (char ***)malloc(sizeof(char **) * 27)) == NULL)
		return (NULL);
	while (1)
	{
		ret = ft_read_figure(fd, figures + i, cords + i, i);
		if (ret == 0)
			return (NULL);
		else if (ret == 1)
			return (figures);
		ret = ft_read_n(fd, figures + i, cords + i);
		if (ret == 0)
			return (NULL);
		else if (ret == 1)
			return (figures);
		i++;
	}
}

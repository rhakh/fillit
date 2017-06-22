/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <rhakh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:49:52 by sbondar           #+#    #+#             */
/*   Updated: 2016/12/27 21:43:05 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_bad_input(int argc, char **argv)
{
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		exit(1);
	}
	fd = ft_file_open(argv[1]);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (fd);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		***fs;
	int			len;
	t_ficord	**cords;

	fd = ft_bad_input(argc, argv);
	cords = (t_ficord **)malloc(sizeof(t_ficord *) * 27);
	fs = ft_get_figures(fd, cords);
	if (fs == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	len = 0;
	while (cords[len] != NULL)
		len++;
	ft_get_result(cords, len);
	close(fd);
	return (0);
}

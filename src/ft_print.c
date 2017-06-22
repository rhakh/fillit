/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbondar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:52:42 by sbondar           #+#    #+#             */
/*   Updated: 2016/12/04 14:52:42 by sbondar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_res(char **res, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
			ft_putchar(res[i][j]);
		if (i != count - 1)
			ft_putendl("");
	}
	ft_putstr("\n");
}

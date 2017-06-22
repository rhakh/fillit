/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <rhakh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 20:53:03 by rhakh             #+#    #+#             */
/*   Updated: 2016/12/27 21:49:00 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count(char *str, char sign)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == sign)
			res++;
		i++;
	}
	return (res);
}

int			ft_check_n(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 20)
	{
		if (j == 4)
		{
			if (str[i] == '\n')
				j = -1;
			else
				return (0);
		}
		i++;
		j++;
	}
	return (1);
}

int			ft_check(char *str)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		if (str[i] == '#')
			return (ft_check_form(str, i + 1, 0, 0));
	}
	return (0);
}

int			ft_check_form(char *str, int position, int counter, int shift)
{
	if (str[position - 1] == '#' && counter != 4 && ++counter)
	{
		if (position < 16 && counter != 4 && shift != -5)
			counter = ft_check_form(str, position + 5, counter, 5);
		if (position > 5 && counter != 4 && shift != 5)
			counter = ft_check_form(str, position - 5, counter, -5);
		if (position % 5 != 1 && counter != 4 && shift != 1)
			counter = ft_check_form(str, position - 1, counter, -1);
		if (position % 5 != 4 && counter != 4 && shift != -1)
			counter = ft_check_form(str, position + 1, counter, 1);
	}
	return (counter);
}

int			ft_figure_check(char *str)
{
	if (ft_count(str, '#') != 4)
		return (0);
	if (ft_count(str, '.') != 12)
		return (0);
	if (ft_count(str, '\n') != 4)
		return (0);
	if (ft_check(str) != 4)
		return (0);
	if (ft_check_n(str) != 1)
		return (0);
	return (1);
}

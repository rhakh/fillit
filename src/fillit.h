/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhakh <rhakh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:13:29 by rhakh             #+#    #+#             */
/*   Updated: 2016/12/27 21:33:56 by rhakh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_cord
{
	char			x;
	char			y;
}					t_cord;

typedef struct		s_ficord
{
	t_cord			d[4];
	char			lett;
}					t_ficord;

int					ft_bad_input(int argc, char **argv);
int					ft_file_open(char *str);
char				***ft_get_figures(int fd, t_ficord **cords);
char				**ft_get_figure(char *buf);
int					ft_check_form(char *str,
					int position, int counter, int shift);
int					ft_figure_check(char *str);
int					ft_count(char *str, char sign);
int					ft_check_n(char *str);
int					ft_check(char *str);
void				ft_get_result(t_ficord **cords, int len);
char				**ft_get_field(int len);
int					ft_fillit(t_ficord **cords,
					int i, char **res, int res_len);
t_ficord			*ft_get_cords(char **figure);
void				ft_erase_figure(t_ficord *cord, t_cord pos, char **res);
void				ft_do_insert(t_ficord *cord, t_cord pos, char **res);
int					ft_check_insert(t_ficord *cord,
					t_cord pos, char **res, int res_len);
void				ft_print_res(char **res, int count);
int					ft_norm_sqrt(int len);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);

#endif

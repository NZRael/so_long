/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:36:52 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/05 11:39:31 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	int		count_c;
	int		count_p;
	int		count_e;
	int		x;
	int		y;
	int		i;
	int		j;
}	t_data;

typedef struct s_mini
{
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*ground;
	void	*walls;
	void	*coins;
	void	*boatexit;
	int		movs;
}	t_mini;

typedef struct s_all
{
	char	**map;
	char	**tmp;
	int		xsize;
	int		ysize;
	int		xplayer;
	int		yplayer;
	int		xexit;
	int		yexit;
	int		nmb_of_coll;
	t_mini	mini;
	t_data	data;
}	t_all;

void	check_argv(int argc, char **argv);
int		ft_get_nbr_line(char *argv);
void	ft_check_mapfile(char *mapfile);

void	ft_create_mapelem(t_all *all);

void	ft_map(t_all *all, char *argv);
void	ft_verif_mapform(t_all *all);
void	ft_verif_mapwalls(t_all *all);

void	ft_verif_elem(t_all *all);
int		ft_check_elem(t_all *all);
void	ft_count_elem(t_all *all);

void	ft_go_to_exit(t_all *all);
void	ft_find_player(t_all *all);
void	ft_find_exit(t_all *all);
void	ft_if_exit(t_all *all, int x, int y);
void	ft_if_players(t_all *all, int x, int y);
void	ft_verif_coins(t_all *all);

int		ft_keyboard(int key, t_all *all);
void	up(t_all *all);
void	down(t_all *all);
void	right(t_all *all);
void	left(t_all *all);

void	ft_show_map(t_all *all);
void	ft_sprites(t_all *all);

void	wall(t_all *all);
void	ground(t_all *all);
void	player(t_all *all);
void	boatexit(t_all *all);
void	coins(t_all *all);

void	ft_error(char *str);
int		quit(t_all *all);

#endif

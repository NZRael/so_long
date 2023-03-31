/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:36:52 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/31 16:04:48 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_enemy
{
	int		ypos;
	int		xpos;
	int		dire;
	void	*frames[2];
}	t_enemy;

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
	void	*player[4];
	void	*ground;
	void	*walls;
	void	*coins[2];
	void	*boatexit;
	void	*ennemy[2];
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
	int		dir;
	int		coin;
	t_enemy	enemy;
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
void	ft_verif_game(t_all *all);

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

int		ft_update(t_all *all);
void	ft_data(t_all *all);

void	ft_init_enemy(t_all *all);
void	ft_move_enemy(t_all *all);
void	enemy(t_all *all);
int		ft_is_collision(int x, int y, t_all *all);

void	ft_error(char *str);
int		quit(t_all *all);

#endif
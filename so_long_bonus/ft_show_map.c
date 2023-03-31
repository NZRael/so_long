/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:05:27 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/31 16:04:15 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_sprites(t_all *all)
{
	int	x;
	int	y;

	ft_data(all);
	all->mini.walls = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/waterwalls.xpm", &x, &y);
	all->mini.ground = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/sand.xpm", &x, &y);
	all->mini.coins[0] = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/coin.xpm", &x, &y);
	all->mini.coins[1] = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/coinup.xpm", &x, &y);
	all->mini.boatexit = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/boatexit.xpm", &x, &y);
	if (!all->mini.walls || !all->mini.ground ||!all->mini.coins[0]
		|| !all->mini.coins[1] || !all->mini.boatexit)
		ft_error("Invalid images\n");
}

void	ft_data(t_all *all)
{
	int	x;
	int	y;

	all->mini.player[0] = mlx_xpm_file_to_image(
			all->mini.mlx, "so_long_bonus/textures/luffyup.xpm", &x, &y);
	all->mini.player[1] = mlx_xpm_file_to_image(
			all->mini.mlx, "so_long_bonus/textures/luffyright.xpm", &x, &y);
	all->mini.player[2] = mlx_xpm_file_to_image(
			all->mini.mlx, "so_long_bonus/textures/luffydown.xpm", &x, &y);
	all->mini.player[3] = mlx_xpm_file_to_image(
			all->mini.mlx, "so_long_bonus/textures/luffyleft.xpm", &x, &y);
	if (!all->mini.player[0] || !all->mini.player[1] || !all->mini.player[2]
		|| !all->mini.player[3])
		ft_error("Invalid images\n");
}

int	ft_update(t_all *all)
{
	static int	frame = 0;
	static int	time = 0;

	frame++;
	time++;
	ft_show_map(all);
	if (frame >= 35)
	{
		if (all->coin == 0)
			all->coin = 1;
		else
			all->coin = 0;
		frame = 0;
	}
	if (time >= 10)
	{
		ft_move_enemy(all);
		time = 0;
	}
	return (0);
}

void	ft_show_map(t_all *all)
{
	ft_sprites(all);
	all->data.y = -1;
	all->data.i = 0;
	while (++all->data.y < all->ysize)
	{
		all->data.x = -1;
		all->data.j = 0;
		while (++all->data.x < all->xsize)
		{
			if (all->map[all->data.y][all->data.x] == '1')
				wall(all);
			if (all->map[all->data.y][all->data.x] == '0')
				ground(all);
			if (all->map[all->data.y][all->data.x] == 'C')
				coins(all);
			if (all->map[all->data.y][all->data.x] == 'P')
				player(all);
			if (all->map[all->data.y][all->data.x] == 'E')
				boatexit(all);
			all->data.j += 60;
		}
		all->data.i += 60;
	}
	enemy(all);
}

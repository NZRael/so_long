/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:05:27 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/23 16:25:39 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprites(t_all *all)
{
	int	x;
	int	y;

	all->mini.walls = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/walls.xpm", &x, &y);
	all->mini.ground = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/ground.xpm", &x, &y);
	all->mini.coins = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/COINS.xpm", &x, &y);
	all->mini.player = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/player.xpm", &x, &y);
	all->mini.closedexit = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/closedexit.xpm", &x, &y);
	all->mini.openexit = mlx_xpm_file_to_image(all->mini.mlx,
			"./textures/openexit.xpm", &x, &y);
	if (!all->mini.walls || !all->mini.ground || !all->mini.player
		|| !all->mini.coins || !all->mini.openexit || !all->mini.closedexit)
		ft_error("Invalid images\n");
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
				door(all);
			all->data.j += 60;
		}
		all->data.i += 60;
	}
}

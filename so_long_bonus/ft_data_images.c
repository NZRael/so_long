/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:06:21 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/04 10:06:54 by sboetti          ###   ########.fr       */
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
	all->mini.game_over = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/game_over.xpm", &x, &y);
	if (!all->mini.walls || !all->mini.ground ||!all->mini.coins[0]
		|| !all->mini.coins[1] || !all->mini.boatexit || !all->mini.game_over)
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

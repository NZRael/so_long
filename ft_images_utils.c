/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:26 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/24 13:07:49 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall(t_all *all)
{
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.walls, all->data.j, all->data.i);
}

void	ground(t_all *all)
{
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.ground, all->data.j, all->data.i);
}

void	player(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.player, all->data.j, all->data.i);
}

void	boatexit(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.boatexit, all->data.j, all->data.i);
}

void	coins(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.coins, all->data.j, all->data.i);
}

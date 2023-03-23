/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:26 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/23 16:13:44 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	wall(t_all *all)
{
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.walls, all->data.j, all->data.i);
	// mlx_string_put(all->mini.mlx, all->mini.mlx_win,
	// 	20, 10, 0xFFFFF0, ft_itoa(all->mini.movs));
}

void	ground(t_all *all)
{
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.ground, all->data.j, all->data.i);
	// mlx_string_put(all->mini.mlx, all->mini.mlx_win,
	// 	20, 10, 0xFFFFF0, ft_itoa(all->mini.movs));
}

void	player(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.player, all->data.j, all->data.i);
	// mlx_string_put(all->mini.mlx, all->mini.mlx_win,
	// 	20, 10, 0xFFFFF0, ft_itoa(all->mini.movs));
}

void	door(t_all *all)
{
	ground(all);
	if (all->nmb_of_coll == 0)
		mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
			all->mini.openexit, all->data.j, all->data.i);
	else
		mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
			all->mini.closedexit, all->data.j, all->data.i);
	// mlx_string_put(all->mini.mlx, all->mini.mlx_win,
	// 	20, 10, 0xFFFFF0, ft_itoa(all->mini.movs));
}

void	coins(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.coins, all->data.j, all->data.i);
	// mlx_string_put(all->mini.mlx, all->mini.mlx_win,
	// 	20, 10, 0xFFFFF0, ft_itoa(all->mini.movs));
}
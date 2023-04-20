/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:26 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/13 11:46:58 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	wall(t_all *all)
{
	char	*count;

	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.walls, all->data.j, all->data.i);
	count = ft_itoa(all->mini.movs);
	mlx_string_put(all->mini.mlx, all->mini.mlx_win, 15, 15, 0xFFFFF0,
		count);
	free(count);
}

void	ground(t_all *all)
{
	char	*count;

	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.ground, all->data.j, all->data.i);
	count = ft_itoa(all->mini.movs);
	mlx_string_put(all->mini.mlx, all->mini.mlx_win, 15, 15, 0xFFFFF0,
		count);
	free(count);
}

void	player(t_all *all)
{
	char	*count;

	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.player[all->dir], all->data.j, all->data.i);
	count = ft_itoa(all->mini.movs);
	mlx_string_put(all->mini.mlx, all->mini.mlx_win, 15, 15, 0xFFFFF0,
		count);
	free(count);
}

void	boatexit(t_all *all)
{
	char	*count;

	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.boatexit, all->data.j, all->data.i);
	count = ft_itoa(all->mini.movs);
	mlx_string_put(all->mini.mlx, all->mini.mlx_win, 15, 15, 0xFFFFF0,
		count);
	free(count);
}

void	coins(t_all *all)
{
	char	*count;

	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->mini.coins[all->coin], all->data.j, all->data.i);
	count = ft_itoa(all->mini.movs);
	mlx_string_put(all->mini.mlx, all->mini.mlx_win, 15, 15, 0xFFFFF0,
		count);
	free(count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:05:27 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/04 11:09:33 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_update_coin(t_all *all)
{
	static int	frame = 0;

	frame++;
	if (frame >= 30)
	{
		if (all->coin == 0)
			all->coin = 1;
		else
			all->coin = 0;
		frame = 0;
	}
	return ;
}

int	ft_frame_enemy(t_all *all)
{
	static int	frame = 0;

	frame++;
	if (frame >= 1)
	{
		ft_die(all);
		frame = 0;
	}
	return (0);
}

int	ft_update(t_all *all)
{
	static int	time = 0;
	static int	sec = 0;

	time++;
	sec++;
	ft_show_map(all);
	ft_update_coin(all);
	if (time >= 8)
	{
		ft_move_enemy(all);
		time = 0;
	}
	if (sec >= 1)
	{
		ft_die(all);
		sec = 0;
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

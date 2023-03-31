/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:55:35 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/31 16:10:45 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_enemy(t_all *all)
{
	int	x;
	int	y;

	all->enemy.xpos = ((all->xsize - 1) / 2) * 60;
	all->enemy.ypos = ((all->ysize - 1) / 2) * 60;
	all->enemy.dire = 0;
	all->enemy.frames[0] = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/kaidoright.xpm", &x, &y);
	all->enemy.frames[1] = mlx_xpm_file_to_image(all->mini.mlx,
			"so_long_bonus/textures/kaidoleft.xpm", &x, &y);
	if (!all->enemy.frames[0] || !all->enemy.frames[1])
		ft_error("Invalid images\n");
}

int	ft_is_collision(int x, int y, t_all *all)
{
	if (x < 0 || y < 0 || x >= all->xsize || y >= all->ysize)
		return (1);
	if (all->map[y][x] == '1' || all->map[y][x] == 'C'
		|| all->map[y][x] == 'E')
	{
		if (all->enemy.dire == 0)
				all->enemy.dire = 1;
		else
				all->enemy.dire = 0;
		return (1);
		}
	return (0);
}

void	ft_move_enemy(t_all *all)
{
	int	new_xpos;
	int	new_ypos;

	if (all->map[all->enemy.ypos / 60][all->enemy.xpos / 60] == 'P')
		exit(-1);
	new_xpos = all->enemy.xpos;
	new_ypos = all->enemy.ypos;
	if (all->enemy.dire == 0)
		new_xpos += 60;
	if (all->enemy.dire == 1)
		new_xpos -= 60;
	if (all->map[new_ypos / 60][new_xpos / 60] == 'P')
		exit(-1);
	if (ft_is_collision(new_xpos / 60, new_ypos / 60, all) == 0)
		all->enemy.xpos = new_xpos;
	enemy(all);
}

void	enemy(t_all *all)
{
	ground(all);
	mlx_put_image_to_window(all->mini.mlx, all->mini.mlx_win,
		all->enemy.frames[all->enemy.dire], all->enemy.xpos, all->enemy.ypos);
}
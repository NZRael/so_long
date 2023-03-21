/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_to_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:55:02 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/21 16:25:31 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_if_players(t_all *all, int x, int y)
{
	if (all->tmp[y][x] != '0' && all->tmp[y][x] != 'P'
	&& all->tmp[y][x] != 'C' && all->tmp[y][x] != 'E')
		return ;
	all->tmp[y][x] = 'X';
	ft_if_players(all, x + 1, y);
	ft_if_players(all, x - 1, y);
	ft_if_players(all, x, y - 1);
	ft_if_players(all, x, y + 1);
	return ;
}

// static void	ft_if_exit(t_all *all, int x, int y)
// {
// 	if (all->tmp[y][x] != '0' && all->tmp[y][x] != 'P'
// 	&& all->tmp[y][x] != 'C')
// 		return ;
// 	all->tmp[y][x] = 'E';
// 	ft_if_exit(all, x + 1, y);
// 	ft_if_exit(all, x - 1, y);
// 	ft_if_exit(all, x, y - 1);
// 	ft_if_exit(all, x, y + 1);
// 	return ;
// }

void	ft_verif_game(t_all *all)
{
	int	x;
	int	y;

	ft_if_players(all, all->xplayer, all->yplayer);
	y = 1;
	while (all->tmp[y])
	{
		x = 1;
		while (all->tmp[y][x])
		{
			if (all->tmp[y][x] == 'E')
				ft_error("Player can't reach exit.\n");
			if (all->tmp[y][x] == 'C')
				ft_error("All collectibles can't be picked up\n");
			x++;
		}
		y++;
	}
}

void	ft_go_to_exit(t_all *all)
{
	int		i;

	i = 0;
	all->tmp = malloc(sizeof(char *) * (all->ysize + 1));
	while (i < all->ysize)
	{
		all->tmp[i] = ft_strdup(all->map[i]);
		i++;
	}
	all->tmp[i] = NULL;
	ft_verif_game(all);
	int	z = 0;
	while (all->tmp[z])
	{
		printf("all->tmp[%d] -> %s", z, all->tmp[z]);
		z++;
	}
}

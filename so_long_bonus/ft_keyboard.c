/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:12:50 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/31 12:11:58 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up(t_all *all)
{
	ft_find_player(all);
	if (all->map[all->yplayer - 1][all->xplayer] == '1')
		return ;
	if (all->map[all->yplayer - 1][all->xplayer] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	if (all->map[all->yplayer - 1][all->xplayer] == 'E'
	&& all->nmb_of_coll == 0)
		exit(0);
	if (all->map[all->yplayer - 1][all->xplayer] == 'C')
	{
		all->map[all->yplayer - 1][all->xplayer] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
		all->nmb_of_coll--;
	}
	else
	{
		all->map[all->yplayer - 1][all->xplayer] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
	}
	all->mini.movs++;
}

void	down(t_all *all)
{
	ft_find_player(all);
	if (all->map[all->yplayer + 1][all->xplayer] == '1')
		return ;
	if (all->map[all->yplayer + 1][all->xplayer] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	if (all->map[all->yplayer + 1][all->xplayer] == 'E'
	&& all->nmb_of_coll == 0)
		exit(0);
	if (all->map[all->yplayer + 1][all->xplayer] == 'C')
	{
		all->map[all->yplayer + 1][all->xplayer] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
		all->nmb_of_coll--;
	}
	else
	{
		all->map[all->yplayer + 1][all->xplayer] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
	}
	all->mini.movs++;
}

void	right(t_all *all)
{
	ft_find_player(all);
	if (all->map[all->yplayer][all->xplayer + 1] == '1')
		return ;
	if (all->map[all->yplayer][all->xplayer + 1] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	if (all->map[all->yplayer][all->xplayer + 1] == 'E'
	&& all->nmb_of_coll == 0)
		exit(0);
	if (all->map[all->yplayer][all->xplayer + 1] == 'C')
	{
		all->map[all->yplayer][all->xplayer + 1] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
		all->nmb_of_coll--;
	}
	else
	{
		all->map[all->yplayer][all->xplayer + 1] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
	}
	all->mini.movs++;
}

void	left(t_all *all)
{
	ft_find_player(all);
	if (all->map[all->yplayer][all->xplayer - 1] == '1')
		return ;
	if (all->map[all->yplayer][all->xplayer - 1] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	if (all->map[all->yplayer][all->xplayer - 1] == 'E'
	&& all->nmb_of_coll == 0)
		exit(0);
	if (all->map[all->yplayer][all->xplayer - 1] == 'C')
	{
		all->map[all->yplayer][all->xplayer - 1] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
		all->nmb_of_coll--;
	}
	else
	{
		all->map[all->yplayer][all->xplayer - 1] = 'P';
		all->map[all->yplayer][all->xplayer] = '0';
	}
	all->mini.movs++;
}

int	ft_keyboard(int key, t_all *all)
{
	if (key == 126 || key == 13)
	{
		all->dir = 0;
		up(all);
	}
	if (key == 125 || key == 1)
	{
		all->dir = 2;
		down(all);
	}
	if (key == 124 || key == 2)
	{
		all->dir = 1;
		right(all);
	}
	if (key == 123 || key == 0)
	{
		all->dir = 3;
		left(all);
	}
	if (key == 53)
		exit(0);
	ft_show_map(all);
	return (0);
}

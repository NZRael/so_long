/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:12:50 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/06 13:00:12 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_all *all)
{
	if (all->map[all->yplayer - 1][all->xplayer] == '1')
		return ;
	if (all->map[all->yplayer - 1][all->xplayer] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	ft_putstr_fd("Movs : ", 1);
	if (all->map[all->yplayer - 1][all->xplayer] == 'E'
	&& all->nmb_of_coll == 0)
	{
		ft_putnbr_fd(all->mini.movs, 1);
		exit(0);
	}
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
	ft_putnbr_fd(all->mini.movs++, 1);
	ft_putstr_fd("\n", 1);
}

void	down(t_all *all)
{
	if (all->map[all->yplayer + 1][all->xplayer] == '1')
		return ;
	if (all->map[all->yplayer + 1][all->xplayer] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	ft_putstr_fd("Movs : ", 1);
	if (all->map[all->yplayer + 1][all->xplayer] == 'E'
	&& all->nmb_of_coll == 0)
	{
		ft_putnbr_fd(all->mini.movs, 1);
		exit(0);
	}
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
	ft_putnbr_fd(all->mini.movs++, 1);
	ft_putstr_fd("\n", 1);
}

void	right(t_all *all)
{
	if (all->map[all->yplayer][all->xplayer + 1] == '1')
		return ;
	if (all->map[all->yplayer][all->xplayer + 1] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	ft_putstr_fd("Movs : ", 1);
	if (all->map[all->yplayer][all->xplayer + 1] == 'E'
	&& all->nmb_of_coll == 0)
	{
		ft_putnbr_fd(all->mini.movs, 1);
		exit(0);
	}
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
	ft_putnbr_fd(all->mini.movs++, 1);
	ft_putstr_fd("\n", 1);
}

void	left(t_all *all)
{
	if (all->map[all->yplayer][all->xplayer - 1] == '1')
		return ;
	if (all->map[all->yplayer][all->xplayer - 1] == 'E'
	&& all->nmb_of_coll != 0)
		return ;
	ft_putstr_fd("Movs : ", 1);
	if (all->map[all->yplayer][all->xplayer - 1] == 'E'
	&& all->nmb_of_coll == 0)
	{
		ft_putnbr_fd(all->mini.movs, 1);
		exit(0);
	}
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
	ft_putnbr_fd(all->mini.movs++, 1);
	ft_putstr_fd("\n", 1);
}

int	ft_keyboard(int key, t_all *all)
{
	if (key == 126 || key == 13)
	{
		ft_find_player(all);
		up(all);
	}
	if (key == 125 || key == 1)
	{
		ft_find_player(all);
		down(all);
	}
	if (key == 124 || key == 2)
	{
		ft_find_player(all);
		right(all);
	}
	if (key == 123 || key == 0)
	{
		ft_find_player(all);
		left(all);
	}
	if (key == 53)
		exit(0);
	ft_show_map(all);
	return (0);
}

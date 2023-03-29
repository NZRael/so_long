/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:16:09 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/29 10:45:23 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_exit(t_all *all)
{
	all->yexit = 1;
	while (all->yexit < all->ysize - 1)
	{
		all->xexit = 1;
		while (all->xexit < all->xsize - 1)
		{
			if (all->map[all->yexit][all->xexit] == 'P')
				return ;
			all->xexit++;
		}
		all->yexit++;
	}
}

void	ft_find_player(t_all *all)
{
	all->yplayer = 1;
	while (all->yplayer < all->ysize - 1)
	{
		all->xplayer = 1;
		while (all->xplayer < all->xsize - 1)
		{
			if (all->map[all->yplayer][all->xplayer] == 'P')
				return ;
			all->xplayer += 1;
		}
		all->yplayer += 1;
	}
}

int	main(int argc, char **argv)
{
	t_all	all;

	check_argv(argc, argv);
	all.ysize = ft_get_nbr_line(argv[1]);
	all.map = malloc(sizeof(char *) * (all.ysize + 1));
	ft_map(&all, argv[1]);
	ft_verif_mapform(&all);
	ft_verif_mapwalls(&all);
	ft_verif_elem(&all);
	all.nmb_of_coll = ft_check_elem(&all);
	ft_find_player(&all);
	ft_find_exit(&all);
	ft_go_to_exit(&all);
	all.mini.mlx = mlx_init();
	all.mini.mlx_win = mlx_new_window(all.mini.mlx,
			((all.xsize - 1) * 60), (all.ysize * 60), "so_long");
	mlx_hook(all.mini.mlx_win, 2, 0, ft_keyboard, &all);
	ft_show_map(&all);
	mlx_hook(all.mini.mlx_win, 17, 0, (int (*)())quit, &all);
	mlx_loop(all.mini.mlx);
	return (0);
}

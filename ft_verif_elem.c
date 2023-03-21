/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:53:28 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/16 15:26:15 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_elem(t_all*all)
{
	if (all->data.count_e != 1)
		ft_error("Number of exit invalid\n");
	if (all->data.count_p != 1)
		ft_error("Number of player invalid\n");
	if (all->data.count_c < 1)
		ft_error("Number of collectibles invalid\n");
}

int	ft_check_elem(t_all *all)
{
	int		i;
	int		j;

	all->data.count_p = 0;
	all->data.count_c = 0;
	all->data.count_e = 0;
	i = 0;
	while (i++ < all->ysize - 1)
	{
		j = 0;
		while (j < all->xsize - 1)
		{
			if (all->map[i][j] == 'E')
				all->data.count_e++;
			if (all->map[i][j] == 'P')
				all->data.count_p++;
			if (all->map[i][j] == 'C')
				all->data.count_c++;
			j++;
		}
	}
	ft_count_elem(all);
	return (all->data.count_c);
}

void	ft_verif_elem(t_all *all)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < all->ysize - 1)
	{
		j = 1;
		while (j < (all->xsize - 1))
		{
			if (all->map[i][j] != '0' && all->map[i][j] != 'E'
			&& all->map[i][j] != 'C' && all->map[i][j] != 'P'
			&& all->map[i][j] != '1')
				ft_error("Invalid argument in map (must have P, C, E, 1, 0)\n");
			j++;
		}
		i++;
	}
}

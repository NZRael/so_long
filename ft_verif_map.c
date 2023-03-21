/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:00 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/17 11:53:25 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_nbr_line(char *argv)
{
	int	fd;
	int	nbr_line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Open file\n");
	nbr_line = 0;
	while (get_next_line(fd))
		nbr_line++;
	if (nbr_line == 0)
		ft_error("Empty File\n");
	close(fd);
	return (nbr_line);
}

void	ft_verif_mapwalls(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < all->xsize - 1)
	{
		if (all->map[i][j] != '1')
			ft_error("Map's walls invalid\n");
		j++;
	}
	while (i < all->ysize - 1)
	{
		if (all->map[i][0] != '1'
		&& all->map[i][all->xsize - 1] != '1')
			ft_error("Map's walls invalid\n");
		i++;
	}
	j = 0;
	while (j < all->xsize - 1)
	{
		if (all->map[all->ysize - 1][j] != '1')
			ft_error("Map's walls invalid\n");
		j++;
	}
}

void	ft_verif_mapform(t_all *all)
{
	int	i;

	i = 1;
	while (i < all->ysize - 1)
	{
		if (ft_strlen(all->map[i]) != ft_strlen(all->map[0]))
			ft_error("Map form invalid\n");
		i++;
	}
	// printf("ft_strlen(all->map[%d])+1 >>>>>> %lu\n", i, (ft_strlen(all->map[i]) + 1));
	// printf("ft_strlen(all->map[0]) >>>>>> %lu\n", ft_strlen(all->map[0]));
	if ((ft_strlen(all->map[i]) + 1) != ft_strlen(all->map[0]))
		ft_error("Map form invalid\n");
	return ;
}

void	ft_map(t_all *all, char *argv)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Open file\n");
	line = get_next_line(fd);
	if (!line)
		return (free(line));
	while (line)
	{
		tmp = ft_strdup(line);
		free(line);
		all->map[i] = tmp;
		line = get_next_line(fd);
		i++;
	}
	all->xsize = ft_strlen(all->map[0]);
	all->ysize = i;
	all->map[i] = NULL;
	close(fd);
	return ;
}

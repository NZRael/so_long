/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:00 by sboetti           #+#    #+#             */
/*   Updated: 2023/04/17 09:32:37 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_sl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc (ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof (char));
	if (!p)
		return (NULL);
	while (s1[i])
		p[k++] = s1[i++];
	while (s2[j])
		p[k++] = s2[j++];
	p[k] = '\0';
	free (s1);
	s1 = NULL;
	return (p);
}

int	ft_get_nbr_line(char *argv)
{
	int		fd;
	int		nbr_line;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Open file\n");
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error("Empty File\n");
	}
	nbr_line = 0;
	while (line)
	{
		free(line);
		nbr_line++;
		line = get_next_line(fd);
	}
	free(line);
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
		|| all->map[i][all->xsize - 2] != '1')
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
	while (i < all->ysize)
	{
		line = get_next_line(fd);
		tmp = ft_strdup(line);
		free(line);
		all->map[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	all->xsize = ft_strlen(all->map[0]);
	all->map[i] = NULL;
	close(fd);
}

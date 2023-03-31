/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboetti <sboetti@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:30:27 by sboetti           #+#    #+#             */
/*   Updated: 2023/03/29 15:32:34 by sboetti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_argv(int argc, char **argv)
{
	int		start;
	char	*ber;

	if (argc != 2)
		ft_error("Expected 2 arguments for argc\n");
	ft_check_mapfile(argv[1]);
	start = ft_strlen(argv[1]) - 4;
	ber = ft_substr(argv[1], start, 4);
	if (ft_strcmp(ber, ".ber") != 0)
		ft_error("Map must be .ber\n");
	return (free(ber));
}

void	ft_check_mapfile(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_DIRECTORY);
	if (fd == -1)
	{
		close(fd);
		return ;
	}
	ft_error("Map must be a file, and not a directory\n");
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

int	quit(t_all *all)
{
	free(all->mini.mlx);
	exit(0);
}

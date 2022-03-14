/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:14:08 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/07 12:17:46 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	freemap(t_map *map)
{
	int	i;

	if (map -> map)
	{
		i = -1;
		while (map -> map[++i])
			free(map->map[i]);
		free (map -> map);
	}
	if ((map -> mlx && map->win))
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
}

void	ft_error(char *str, int c, t_map *map)
{
	printf("%s\n", str);
	if (c == 1)
		freemap(map);
	exit(0);
}

void	all_ok(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= map -> cy -1)
	{
		j = -1;
		while (++j <= map -> cx)
		{
			if (map -> map[i][j] == 'C')
			{
				map -> cc += 1;
			}
		}
	}
	if (map -> cc < 1)
		ft_error("Error\n There arent collectionables man", 0, map);
}

void	only_five(t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = -1;
	c = 0;
	while (++i <= map -> cy -1)
	{
		j = -1;
		while (++j <= map -> cx - 1)
		{
			if (map -> map[i][j] != 'P' && map -> map[i][j] != 'C' &&
					map -> map[i][j] != 'E' && map -> map[i][j] != '0' &&
					map -> map[i][j] != '1')
				c++;
		}
	}
	if (c > 0)
		ft_error("Error\n What are u triyng to put here?", 0, map);
}

void	border(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= map -> cy - 1)
	{
		j = -1;
		while (++j <= map -> cx - 1)
		{
			if (i == 0 | i == map -> cy - 1)
				if (map -> map[i][j] != '1')
					ft_error("Error\n Map not closed man", 1, map);
			if (j == 0 | j == map -> cx - 1)
				if (map -> map[i][j] != '1')
					ft_error("Error\n Map not closed man", 1, map);
		}
	}
}

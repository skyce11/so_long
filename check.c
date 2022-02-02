/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:14:08 by migonzal          #+#    #+#             */
/*   Updated: 2022/02/02 11:39:33 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void freemap(t_map *map)
{
	int i;

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

void ft_error(char *str, int c, t_map *map)
{
	printf("%s\n", str);
	if (c == 1)
		freemap(map);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:06:36 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/14 12:42:06 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_true(t_map *map)
{
	int	i;
	int	j;
	int	ce;
	int	cp;

	i = -1;
	ce = 0;
	cp = 0;
	while (++i <= map -> cy -1)
	{
		j = -1;
		while (++j <= map -> cx)
		{
			if (map -> map[i][j] == 'P')
				cp++;
			if (map -> map[i][j] == 'E')
				ce++;
		}
	}
	if (cp != 1)
		ft_error("Error\n Whats wrong with the player?", 0, map);
	if (ce != 1)
		ft_error("Error\n Whats wrong with the exit?", 0, map);
}

void	aux_right(t_map *map)
{
	if (map ->map[map->px][map->py +1] == 'E' && map ->cc != 0)
		stay_right(map);
	else
		move_right(map);
}

void	aux_left(t_map *map)
{
	if (map->map[map->px][map->py -1] == 'E' && map -> cc != 0)
		stay_left(map);
	else
		move_left(map);
}

void	aux_up(t_map *map)
{
	if (map->map[map->px -1][map->py] == 'E' && map -> cc != 0)
		stay_up(map);
	else
		move_up(map);
}

void	aux_down(t_map *map)
{
	if (map->map[map->px +1][map->py] == 'E' && map -> cc != 0)
		stay_down(map);
	else
		move_down(map);
}

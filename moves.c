/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:00:39 by migonzal          #+#    #+#             */
/*   Updated: 2022/02/02 10:24:57 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"


int moves (int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124 && map -> map[map->px][map->py + 1] != '1')
		move_right(map);
	if (keycode == 123 && map -> map[map->px][map->py - 1] != '1')
		move_left(map);
	if (keycode == 126 && map -> map[map->px - 1][map->py] != '1')
		move_up(map);
	if (keycode == 125 && map -> map[map->px + 1][map->py] != '1')
		move_down(map);
	return (0);
}


int move_right(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> py += 1;
	map -> mov += 1;
	printf("El número actúal de movimientos es: %d\n", map -> mov);
	put_image(map, map->px, map->py, "./images/link_right.xpm");

	return (0);
}

int move_left(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> py -= 1;
	map -> mov += 1;
	printf("El número actúal de movimientos es: %d\n", map -> mov);
	put_image(map, map->px, map->py, "./images/link_left.xpm");

	return (0);
}

int move_up(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> px -= 1;
	map -> mov += 1;
	printf("El número actúal de movimientos es: %d\n", map -> mov);
	put_image(map, map->px, map->py, "./images/link_up.xpm");

	return (0);
}

int move_down(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> px += 1;
	map -> mov += 1;
	printf("El número actúal de movimientos es: %d\n", map -> mov);
	put_image(map, map->px, map->py, "./images/link.xpm");

	return(0);
}

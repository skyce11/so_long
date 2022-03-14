/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:00:39 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/07 12:19:48 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	moves(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2 && map -> map[map->px][map->py + 1] != '1')
		aux_right(map);
	if (keycode == 0 && map -> map[map->px][map->py - 1] != '1')
		aux_left(map);
	if (keycode == 13 && map -> map[map->px - 1][map->py] != '1')
		aux_up(map);
	if (keycode == 1 && map -> map[map->px + 1][map->py] != '1')
		aux_down(map);
	if (map -> map[map -> px][map -> py] == 'E' && map -> cc == 0)
	{	
		printf("Done");
		exit(0);
	}
	if (map -> map[map -> px][map -> py] == 'C')
	{
		map -> map[map -> px][map -> py] = '0';
		map -> cc -= 1;
	}
	return (0);
}

int	move_right(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> py += 1;
	map -> mov += 1;
	map -> movs = ft_itoa(map -> mov);
	put_image(map, 0, 0, "./images/tree.xpm");
	mlx_string_put(map -> mlx, map -> win, 1, 1, 0, map -> movs);
	printf("El número actúal de movimientos es: %d\n", map->mov);
	put_image(map, map->px, map->py, "./images/link_right.xpm");
	return (0);
}

int	move_left(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> py -= 1;
	map -> mov += 1;
	map -> movs = ft_itoa(map -> mov);
	put_image(map, 0, 0, "./images/tree.xpm");
	mlx_string_put(map -> mlx, map -> win, 1, 1, 0, map -> movs);
	printf("El número actúal de movimientos es: %d\n", map->mov);
	put_image(map, map->px, map->py, "./images/link_left.xpm");
	return (0);
}

int	move_up(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> px -= 1;
	map -> mov += 1;
	map -> movs = ft_itoa(map -> mov);
	put_image(map, 0, 0, "./images/tree.xpm");
	mlx_string_put(map -> mlx, map -> win, 1, 1, 0, map -> movs);
	printf("El número actúal de movimientos es: %d\n", map->mov);
	put_image(map, map->px, map->py, "./images/link_up.xpm");
	return (0);
}

int	move_down(t_map *map)
{
	put_image(map, map->px, map->py, "./images/ground.xpm");
	map -> px += 1;
	map -> mov += 1;
	map -> movs = ft_itoa(map -> mov);
	put_image(map, 0, 0, "./images/tree.xpm");
	mlx_string_put(map -> mlx, map -> win, 1, 1, 0, map -> movs);
	printf("El número actúal de movimientos es: %d\n", map->mov);
	put_image(map, map->px, map->py, "./images/link.xpm");
	return (0);
}

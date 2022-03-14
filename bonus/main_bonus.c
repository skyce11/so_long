/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:13:15 by migonzal          #+#    #+#             */
/*   Updated: 2022/03/07 11:54:23 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewin(t_map *map)
{
	freemap(map);
	printf("Done\n");
	exit (EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char const **argv)
{
	t_map	map;

	initiator(&map);
	map.movs = ft_itoa(map.mov);
	parser(argc, argv, &map);
	only_five(&map);
	all_ok(&map);
	all_true(&map);
	border(&map);
	map.mlx = mlx_init(0);
	map.win = mlx_new_window(map.mlx, map.tx, map.ty, "SO_LONG");
	draw_map(&map);
	printf("El número actúal de movimientos es: %d\n", map.mov);
	mlx_key_hook(map.win, moves, &map);
	mlx_hook(map.win, 17, (1L << 17), closewin, &map);
	mlx_string_put(map.mlx, map.win, 1, 1, 0, map.movs);
	mlx_loop(map.mlx);
}

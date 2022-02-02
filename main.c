/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:13:15 by migonzal          #+#    #+#             */
/*   Updated: 2022/02/02 11:27:34 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"

int main(int argc, char const ** argv)
{
	t_map map;
	initiator(&map);
	parser(argc, argv, &map);
//	get_size(&map);
	printf("El número actúal de movimientos es: %d\n", map.mov);
	
	printf("Valor de y: %d\n", map.y);
	printf("Valor de cy: %d\n", map.cy);
	printf("Valor de cx: %d\n", map.cx);
	printf("Valor de tx: %d\n", map.tx);
	printf("Valor de ty: %d\n", map.ty);
//	mountmap(&map);
	map.mlx = mlx_init(0);
	map.win = mlx_new_window(map.mlx, map.tx, map.ty, "SO_LONG");
	draw_map(&map);
	mlx_key_hook(map.win, moves, &map);
	mlx_loop(map.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:50:06 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/31 09:13:43 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "so_long.h"


int main (void)
{
	t_map map;


	map.mov = 0;
	printf("El número actúal de movimientos es: %d\n", map.mov);
	get_size(&map);




	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.tx, map.ty, "SO_LONG");
	draw_map (&map);
	mlx_key_hook(map.win, moves, &map);
	mlx_loop(map.mlx);
}

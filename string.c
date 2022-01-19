/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:23:10 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/18 09:31:33 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "prueba.h"

int key_code (int keycode, t_vars prueba)
{
//	char *string = "esto es una prueba";
	(void) prueba;
	if (keycode == 53)
		exit(0);
//	if (keycode == 36)
//		mlx_string_put(prueba.mlx, prueba.win, 5, 5, 0x000FF00, string);
	else 
	{
		printf("esto escribe\n");
	}
	return (0);
}





int main(void)
{

	t_vars prueba;
	char *string = "esto es una prueba";




	prueba.mlx	= mlx_init();
	prueba.win = mlx_new_window(prueba.mlx, 2000, 2000, "WIP");
	mlx_string_put(prueba.mlx, prueba.win, 100, 100, 0x0FF0000, string);
	mlx_key_hook(prueba.win, key_code, &prueba);
	mlx_loop(prueba.mlx);
}






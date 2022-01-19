/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:53:34 by migonzal          #+#    #+#             */
/*   Updated: 2022/01/18 10:02:17 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
*/

int key_hook(int keycode, t_vars vars)
{
	(void) vars;

	if (keycode == 53)
		exit(0);
	else
	{
		printf("%i\n", keycode);
	}
	return (0);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
